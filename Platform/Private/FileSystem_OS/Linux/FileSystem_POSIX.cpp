#include "Public/Platform_Brii/Platform_FileSystem.h"
#include "Public/Platform_Brii/Log_System/Platform_logCalls.h"
#include "Settings/Settings_FileSystem.h"

//LIBRARIES TO POSIX AND MORE 
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/stat.h>


namespace FS_LinuxDef
{
 using BT_Internal_FS_ID = BT_FileSystemID;

 void link_FS_flags_OpenMode(const BF_Ios::openMode* open_flags, BT_ComponentFlagsInt* flags)
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

Brii_FileSystem::Brii_FileSystem(){};
Brii_FileSystem::~Brii_FileSystem() = default;
Brii_FileSystem::Brii_FileSystem(BT_StringView file_dir, BF_Ios::openMode open_flags, BF_Ios::openPermissions open_permissions)
{
  open_file(file_dir, open_flags, open_permissions);
}

bool Brii_FileSystem::open_file(BT_StringView file_dir, BF_Ios::openMode open_flags, BF_Ios::openPermissions open_permissions)
{
 BT_FlagsInt posix_openFlags {}; 
 FS_LinuxDef::link_FS_flags_OpenMode(&open_flags, &posix_openFlags);

 mode_t posix_permissions { FS_LinuxDef::get_NumPermissions(&open_permissions) };

 // function to open file with POSIX = int open(const char *path, int oflag, ... ); 
 FS_LinuxDef::BT_Internal_FS_ID fs_ID { open(file_dir.data(), posix_openFlags, posix_permissions) };
 //FS_handle->fs_ID = open(file_dir.data(), posix_openFlags, posix_permissions); 
 
  if(fs_ID < 0)
  {
   BRII_LOG("error open file = " + BT_String(file_dir.data()), true);
//   log_System::fileLogger.error("error open file | file = " + temp_creationFileDir);
   return 0;
  }

  FS_handle = new Brii_FileSystemHandle(fs_ID); 

////CONTINUE HERE TO DECLARE IF OPEN GETS AN ERROR,
 ///in obsidian declare the new types values

 return true;
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




