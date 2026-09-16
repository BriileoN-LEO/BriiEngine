
#pragma once 

#include "Settings/Settings_FileSystem.h"
#include "String/stringID_brii.h"

#include <iostream>


struct Brii_FileSystemHandle;

class Brii_FileSystem
{
  private:

  Brii_FileSystemHandle* FS_handle{nullptr}; /// the control handle that it will control per OS
  
  public:
  Brii_FileSystem();
  Brii_FileSystem(BT_StringView file_dir, BF_Ios::openMode open_flags, BF_Ios::openPermissions open_permissions);
  ~Brii_FileSystem();

  bool open_file(BT_StringView file_dir, BF_Ios::openMode open_flags, BF_Ios::openPermissions open_permissions);  
  bool is_open();  
 
    
  void close_file();  
 

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

