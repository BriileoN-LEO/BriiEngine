#include "Public/Platform_Brii/Platform_FileSystem.h"
#include "Public/Platform_Brii/Log_System/Platform_logCalls.h"
#include "Settings/Settings_FileSystem.h"
#include "Localization/LocalizationString_brii.h"

//LIBRARIES TO POSIX AND MORE 
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <cstring>

namespace FS_LinuxDef
{
 using BT_Internal_FS_ID = BT_FileSystemID;
 using BF_FlagsOpenMode = BT_FlagsInt; 

 void link_FS_flags_OpenMode(const BF_Ios::openMode* open_flags, BF_FlagsOpenMode* flags)
 {
   if(*open_flags && BF_Ios::o_createF){ *flags |= O_CREAT; };

   if(*open_flags && BF_Ios::o_rwF || *open_flags && BF_Ios::o_binary){ *flags |= O_RDWR; };

   if(*open_flags && BF_Ios::o_readF) { *flags |= O_RDONLY; }; 

   if(*open_flags && BF_Ios::o_writeF) { *flags |= O_WRONLY; };
  
   if(*open_flags && BF_Ios::o_truncF) { *flags |= O_TRUNC; };

 }

  /////PERMISSIONS MODULE
/*
  ///Values for open permission in c++
  enum class _OPerm_values : BT_ComponentFlags32
 {
  OP_USER_EXECUTE = 100,
  OP_USER_WRITE = 200,
  OP_USER_READ = 400

  OP_GROUP_EXECUTE = 10,
  OP_GROUP_WRITE = 20,
  OP_GROUP_READ = 40,
  
  OP_OTHERG_EXECUTE = 1, 
  OP_OTHERG_EXECUTE = 2, 
  OP_OTHERG_EXECUTE = 4, 
 };
 
 mode_t get_OP_group(const BF_Ios::openPermissions* open_permissions);
 mode_t get_OP_user(const BF_Ios::openPermissions* open_permissions);
*/

 mode_t get_NumPermissions(const BF_Ios::openPermissions* open_permissions)
 {
   if(*open_permissions == BF_Ios::op_standard)
   {
    //prefix = base is octal, not decimal = 0
    //user = read(4) + write(2) + executable(1) = 6
    //group = read(4) = 4
    //other = read(4) = 4 
    return 0644;
   }

   else if(*open_permissions == BF_Ios::op_executable_archive)
   {
    return 0755;
   }

  return 0;
 }


  
/*
 void link_FS_flags(const BF_Ios::openMode* fs_flags, BT_ComponentFlagsInt* flags)
 {
   ///1. OPEN MODE
   link_FS_flags_OpenMode(fs_flags, flags);
 } 
*/

}



///THIS FileSystem Handle only will be use with this file .cpp
struct Brii_FileSystemHandle
{
 FS_LinuxDef::BT_Internal_FS_ID fs_ID{};
 
};

bool Brii_FileSystem::get_sizeBytes_file(int& ID_FS)
{
 struct stat st_Bytes;  ///Review this variable if is acceptable, or declare this struct
 
 if(fstat(ID_FS, &st_Bytes) == -1)
 {
  BRII_LOG_ERROR(BF_log::file_system_t, "error reading bytes from open file");
  return false;
 }
  
 number_bytes = st_Bytes.st_size;
 return true;
}


Brii_FileSystem::Brii_FileSystem(){};
Brii_FileSystem::~Brii_FileSystem()
{
 delete_FS();
}
Brii_FileSystem::Brii_FileSystem(BT_StringView file_dir, BF_Ios::openMode open_flags, BF_Ios::openPermissions open_permissions)
{
  open_file(file_dir, open_flags, open_permissions);
}

bool Brii_FileSystem::open_file(BT_StringView file_dir, BF_Ios::openMode open_flags, BF_Ios::openPermissions open_permissions)
{
 if(access(file_dir.data(), F_OK) == 0)
 {
 FS_LinuxDef::BF_FlagsOpenMode posix_openFlags {}; 
 FS_LinuxDef::link_FS_flags_OpenMode(&open_flags, &posix_openFlags);

 mode_t posix_permissions { FS_LinuxDef::get_NumPermissions(&open_permissions) };

 // function to open file with POSIX = int open(const char *path, int oflag, ... ); 
 FS_LinuxDef::BT_Internal_FS_ID fs_ID { open(file_dir.data(), posix_openFlags, posix_permissions) };
 //FS_handle->fs_ID = open(file_dir.data(), posix_openFlags, posix_permissions); 

  if(fs_ID < 0)
  {
   BRII_LOG("error open file = " + BT_String(file_dir.data()), true);
   close(fs_ID);
//   log_System::fileLogger.error("error open file | file = " + temp_creationFileDir);
   return false;
  }
  
  if(!get_sizeBytes_file(fs_ID))
  {
   close(fs_ID);
   return false; 
  }

  FS_handle = new Brii_FileSystemHandle(fs_ID); 
  
  open_f = open_flags;
  open_p = open_permissions;


////CONTINUE HERE TO DECLARE IF OPEN GETS AN ERROR,
 ///in obsidian declare the new types values
  directoryF_ID = BT_StringID(file_dir.data());
  return true;
 }
 return false;
}

bool Brii_FileSystem::is_open()
{
 if(FS_handle)
 {
  if(FS_handle->fs_ID >= 0)
  {
   return true;
  }

 }
 return false;
}



bool Brii_FileSystem::write_file(const void* data_buffer, ssize_t data_bytes_size, ssize_t offset, const BT_SourceLoc& location_write)
 {
   if(is_open())
  { 
    if((data_buffer == nullptr) || (data_bytes_size > 0))
   {
    BRII_LOG_ERROR(BF_log::file_system_t, "File is not open in localization = " + location_write.get_Str_Info() + " | is not posible to write file", false, true); 
    return false;
   }  
    ssize_t count_bytes_written { pwrite(FS_handle->fs_ID, data_buffer, data_bytes_size, offset) };
    
    if(!is_written(count_bytes_written, location_write))
    {
     if(!is_writtenBytesMatch(count_bytes_written, data_bytes_size, location_write) && count_bytes_written > 0)
     {
      restore_LastBytesWritten();
      return false;
     }
    }

    return true;
   }

  ////CONTINUE HERE
 ///see how to implement the location, create a file to manage the source of location an implement here in the log.
 ///INVESTIGATE
 ///Write the file write_file_Linux en obsidian
  //const BT_String loc_info {location_write
  BRII_LOG_ERROR(BF_log::file_system_t, "File is not open in localization = " + location_write.get_Str_Info() + " | is not posible to write file", false, true);return false; 
 }

bool Brii_FileSystem::is_written(ssize_t& bytes_writing, const BT_SourceLoc& location_write)
 {
   if(bytes_writing < 0)
  {
   BT_String* dir_file { app_BriiEngine::getStr_allDirCategory_f(&directoryF_ID) }; 
   BRII_LOG_ERROR(BF_log::file_system_t, "is not posible write in file = " + *dir_file, false, true, location_write);

   review_file |= BF_Ios::error_write_file;
   return false;
  }
 
  return true;
 }


 bool Brii_FileSystem::is_writtenBytesMatch(ssize_t& bytes_writing, ssize_t& size_bytes_file, const BT_SourceLoc& location_write)
 { 
   if(bytes_writing != size_bytes_file)
  {
   BT_String* dir_file { app_BriiEngine::getStr_allDirCategory_f(&directoryF_ID) };
   BRII_LOG_ERROR(BF_log::file_system_t, "the bytes written not match with the expected bytes to write in file = " + *dir_file, false, true, location_write);
   BRII_LOG_ERROR(BF_log::file_system_t, "memory is full of space before writting in file, liberate space");
 
   review_file |= BF_Ios::error_write_bytes_match;
   return false;
  }
 
  return true;
 }
 
 void Brii_FileSystem::restore_LastBytesWritten()
 {
  //void* buffer {};
  //ssize_t last_bytes = read(FS_handle->fs_ID, buffer, number_bytes);
  BT_String* str_dir { app_BriiEngine::getStr_allDirCategory_f(&directoryF_ID) };
 
  if(!(open_f && BF_Ios::o_truncF))
  {
   close(FS_handle->fs_ID);
   FS_handle = nullptr;
   open_f |= BF_Ios::o_truncF;  
   
   if(!open_file(*str_dir, open_f, open_p))
   { 
    review_file |= BF_Ios::error_open_file;
    return;
   }
  }

  if(ftruncate(FS_handle->fs_ID, number_bytes) == -1)
  {
   BRII_LOG_ERROR(BF_log::file_system_t, "fail restore to last written bytes, file = " + *str_dir); 
   review_file |= BF_Ios::error_truncate_bytes;
   return;
  }
 
  ////implement the pool_thread

  ///CONTINUE HERE 25/09/2026
  ///TRUNCATE and delete the content of file and put the rest of the buffer.
  ///Implement the localization string to solicitud the ID of the string directories to any function
  ///Implement a pool_thread for queue tasks(pile tasks for the general content of the any sistem like this the fileSystem 
  ///Resolve the pile stack to connect the fileSystem Manager with the logManager that will be write in all files of logs
 }
 
 

 
 bool Brii_FileSystem::read_file(void* data_buffer, ssize_t size_bytes_read, ssize_t offset, const BT_SourceLoc& location_read)
 {
   if(is_open())
   { 
    ssize_t count_bytes_read { pread(FS_handle->fs_ID, data_buffer, size_bytes_read, offset) }; 

    return true;
   }

  return false;
 }

 bool Brii_FileSystem::is_read(ssize_t& bytes_read, const BT_SourceLoc& location_read)
 {
  if(bytes_read < 0)
  {
   BT_String* dir_file { app_BriiEngine::getStr_allDirCategory_f(&directoryF_ID) };
   BRII_LOG_ERROR(BF_log::file_system_t, "is not posible read in file = " + *dir_file, false, true, location_read);
   
   review_file |= BF_Ios::error_read_file;
   return false;
  }
 
  return true;
 } 
 
 bool Brii_FileSystem::is_readBytesMatch(ssize_t& bytes_writing, ssize_t& size_bytes_file, const BT_SourceLoc& location_write)
 {
  if(bytes_writing != size_bytes_file)
 {
   BT_String* dir_file { app_BriiEngine::getStr_allDirCategory_f(&directoryF_ID) };
   BRII_LOG_ERROR(BF_log::file_system_t, "the bytes readed not match with the expected bytes to read in file = " + *dir_file, false, true, location_write);
  // BRII_LOG_ERROR(BF_log::file_system_t, "memory is full of space before writting in file, liberate space");

   review_file |= BF_Ios::error_read_bytes_match;
   return false;
  }
 
  return true;
 }

 BT_String Brii_FileSystem::get_error()
 {
  BT_String error_f{};

  if(review_file && BF_Ios::error_open_file)
  {
   error_f += "Error open file\n";
  }

  if(review_file && BF_Ios::error_truncate_bytes)
  {
   error_f += "Error truncate bytes\n";
  }

  return error_f;
 } 

 void Brii_FileSystem::close_file()
{
 close(FS_handle->fs_ID);
 FS_handle->fs_ID = 0;

 directoryF_ID = 0;

 open_f = BF_Ios::o_empty;
 open_p = BF_Ios::op_empty;
 number_bytes = 0;

}


void Brii_FileSystem::delete_FS()
{
 close_file();
 delete FS_handle;
 //delete directoryF_ID;

}

Brii_FS_CallStack_write::Brii_FS_CallStack_write(BT_StringID first_messageID, BT_StringID File_ID)
{
 messagesID.emplace_back(first_messageID);
 this->File_ID = File_ID;

}

void Brii_FileSystem_Manager::insert_FS_stackWrite(BT_StringID writeMessage, BT_StringID File_ID)
{
 auto find_file {std::find_if(pile_Stack_write.begin(), pile_Stack_write.end(), 
                              [&File_ID](Brii_FS_CallStack_write& Psw)
                              {
                               return Psw.File_ID == File_ID;
                              }) };

 if(find_file != pile_Stack_write.end())
 {
  find_file->messagesID.emplace_back(writeMessage);
 }
/*
 for(auto Psw : pile_Stack_write)
  {
    if(Psw.File_ID == File_ID)
    {
     Psw.messagesID.emplace_back(writeMessage);
     return;
    }
  }
*/
  ////IN THE CASE that File_ID not exists in the vector
 
 else if(find_file == pile_Stack_write.end())
 {
  pile_Stack_write.emplace_back(writeMessage, File_ID);
 }
}

void Brii_FileSystem_Manager::write_files_pileStack()
{
  BF_Ios::openMode o_Mode {BF_Ios::o_createF | BF_Ios::o_writeF | BF_Ios::o_truncF};
  BF_Ios::openPermissions o_permission {BF_Ios::op_standard};
 
  BC_FSystem file_to_w {};

  for(auto& Psw : pile_Stack_write)
  {
   BT_String* file_dir { app_BriiEngine::getStr_allDirCategory_f(&Psw.File_ID) }; 
  
   if(file_to_w.open_file(*file_dir, o_Mode, o_permission))
   {
     
     BT_String str_acc{}; ///string accumulation
     ssize_t bytes_Str_acc{};

    for(auto& ms : Psw.messagesID)
    {
     const BT_String* Str_ms {app_BriiEngine::get_Str(&ms)}; 
    
     str_acc += *Str_ms;
     bytes_Str_acc += Str_ms->str_sizeBytes();
    }

     ssize_t bytes_offset { *file_to_w.get_numberBytes() }; 
     const void* buffer_message {reinterpret_cast<const void*>(&str_acc)}; 
     
     if(!file_to_w.write_file(buffer_message, bytes_Str_acc, bytes_offset))
     {
      BRII_LOG_ERROR(BF_log::file_system_t, "not writing message | File System Manager | file: " + *file_dir, false, true);
      continue;
     }
     ///CONTINUE HERE TO write the files with all content of the messages
     ///Read linux_Log.cpp line 69 to read more about whats next

   }
   BRII_LOG_ERROR(BF_log::file_system_t, "not write in file the pile stack | File System Manager | file = " + *file_dir, false, true);
  }

}

void Brii_FileSystem_Manager::clear_pileStackWrite()
{
 pile_Stack_write.clear();

/*

 for(auto& Psw : pile_Stack_write)
 {
  for(auto& ms : Psw.messagesID)
  {
   app_BriiEngine::delete_str_locStr(&ms); 
  }
 }
*/
}




