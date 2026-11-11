
#pragma once 

#include "Settings/Settings_FileSystem.h"
#include "String/stringID_brii.h"
#include "Localization/Public/SourceLocation_brii.h"

//#include <iostream>
//#include <source_location>

struct Brii_FileSystemHandle;

class Brii_FileSystem
{
  private:

  Brii_FileSystemHandle* FS_handle{ nullptr }; /// the control handle that it will control per OS
  BT_StringID directoryF_ID{ nullptr };

  BF_Ios::openMode open_f{};
  BF_Ios::openPermissions open_p{};
  ssize_t number_bytes{}; 
  
  BF_Ios::error_FS review_file{}; 

  bool get_sizeBytes_file(int& ID_FS);

  public:
  Brii_FileSystem();
  Brii_FileSystem(BT_StringView file_dir, BF_Ios::openMode open_flags, BF_Ios::openPermissions open_permissions);
  ~Brii_FileSystem();


  bool open_file(BT_StringView file_dir, BF_Ios::openMode open_flags, BF_Ios::openPermissions open_permissions);
  ///KEY ASPECTS OF open_file function
  ///- if the file_dir no exist in the localization str, it will be saved there if is open correctly, once is closed and destroyed, 
  ///  the string will be destroyed too
  bool is_open();

  bool write_file(const void* data_buffer, ssize_t data_bytes_size, ssize_t offset, const BT_SourceLoc& location_write = BT_SourceLoc{});
  bool is_written(ssize_t& bytes_writing, const BT_SourceLoc& location_write = BT_SourceLoc{}); ///This function see if the bytes was written correctly
  bool is_writtenBytesMatch(ssize_t& bytes_writing, ssize_t& size_bytes_file, const BT_SourceLoc& location_write = BT_SourceLoc{}); ///This functions see if the
  ///match of the bites are written
  void restore_LastBytesWritten();
   bool read_file(void* data_buffer, ssize_t size_bytes_read, ssize_t offset, const BT_SourceLoc& location_read = BT_SourceLoc{});
  bool is_read(ssize_t& bytes_read, const BT_SourceLoc& location_read = BT_SourceLoc{});
  bool is_readBytesMatch(ssize_t& bytes_writing, ssize_t& size_bytes_file, const BT_SourceLoc& location_read = BT_SourceLoc{});

  BT_String get_error();
  const ssize_t* get_numberBytes() const
 {
  return &number_bytes; 
 }

  void close_file(); 
  void delete_FS();

   ///CONTINUE HERE 
  ///create all the Brii_FileSystem 
  ///after read and write the file Log_files.csv to put all the files that will be saved with their number of enum class of each log file 

};

using BC_FSystem = Brii_FileSystem;

/////CONTINUE HERE TO SE HOW TO ABSTRACT THE FILESYSTEM 03/08/2026

struct Brii_FS_CallStack_write
{
  //Brii_FileSystemHandle* FS_handle{};
 // const char* writeMessage{};
  ///remplaced by a vector of messages to write 
  BT_Vector<BT_StringID> messagesID;
  BT_StringID File_ID{}; ///The ID to use localization string to find the path or file to manage what it will do with the file system 
   ////THIS FILE_ID will be not delete
   
  Brii_FS_CallStack_write(BT_StringID first_messageID, BT_StringID File_ID); 

};

class Brii_FileSystem_Manager
{
 private:

 BT_Vector<Brii_FS_CallStack_write> pile_Stack_write{};

 public:
 
 Brii_FileSystem_Manager();
 ~Brii_FileSystem_Manager();
 
  ////This function puts the content to the callstack to write
  ///file_ID is the ID to find in locStr of directories 
 void insert_FS_stackWrite(BT_StringID writeMessage, BT_StringID File_ID);

 void write_files_pileStack();

 void clear_pileStackWrite();

};

using BC_FS_Manager = Brii_FileSystem_Manager;


