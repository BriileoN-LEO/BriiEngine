
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
  BT_StringID* directoryF_ID{ nullptr };

  BF_Ios::openMode open_f{};
  BF_Ios::openPermissions open_p{};
  ssize_t number_bytes{}; 
  
  public:
  Brii_FileSystem();
  Brii_FileSystem(BT_StringView file_dir, BF_Ios::openMode open_flags, BF_Ios::openPermissions open_permissions);
  ~Brii_FileSystem();


  bool open_file(BT_StringView file_dir, BF_Ios::openMode open_flags, BF_Ios::openPermissions open_permissions);
  ///KEY ASPECTS OF open_file function
  ///- if the file_dir no exist in the localization str, it will be saved there if is open correctly, once is closed and destroyed, 
  ///  the string will be destroyed too
  bool is_open();
  bool get_sizeBytes_file(int& ID_FS);
 

  bool write_file(const void* data_buffer, ssize_t data_bytes_size, ssize_t offset, const BT_SourceLoc& location_write = BT_SourceLoc{});
  bool is_writtenBytesMatch(ssize_t& bytes_writing, ssize_t& size_bytes_file, const BT_SourceLoc& location_write = BT_SourceLoc{}); ///This functions see if the
  ///match of the bites are written
  void delete_bytesWritten(ssize_t& bytes_writing);

  bool is_written(ssize_t& bytes_writing, const BT_SourceLoc& location_write = BT_SourceLoc{}); ///This function see if the bytes was written correctly
 
    
  void close_file(); 
 
  void delete_FS(); ////THIS FUNCTION CLEARS THE CLASS TO NOT USE ANYMORE

   ///CONTINUE HERE 
  ///create all the Brii_FileSystem 
  ///after read and write the file Log_files.csv to put all the files that will be saved with their number of enum class of each log file 
 

};


/////CONTINUE HERE TO SE HOW TO ABSTRACT THE FILESYSTEM 03/08/2026

struct Brii_FS_CallStack_write
{
  //Brii_FileSystemHandle* FS_handle{};
  const char* writeMessage{};
  ///remplaced by a vector of messages to write
  std::vector<BT_StringID> messagesID;
  BT_StringID File_ID{}; ///The ID to use localization string to find the path or file to manage what it will do with the file system

};

class Brii_FileSystem_Manager
{
 private:

 std::vector<Brii_FS_CallStack_write> pile_Stack_write{};

 public:
 
 Brii_FileSystem_Manager();
 ~Brii_FileSystem_Manager();
 
  ////This function puts the content to the callstack to write
 void insert_FS_stackWrite(const char* writeMessage, BT_StringID File_ID);


};

using BC_FS_Manager = Brii_FileSystem_Manager;


