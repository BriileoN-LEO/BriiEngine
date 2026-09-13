
#pragma once 

#include "Settings/Settings_FileSystem.h"

#include <iostream>


struct Brii_FileSystemHandle;

class Brii_FileSystem
{
  private:

  Brii_FileSystemHandle* FS_handle{}; /// the control handle that it will control per OS
  
  public:

  bool open_file(BT_StringView file_dir, BF_Ios::openMode open_flags, BF_Ios::openPermissions open_permissions); 
    
  void close_file();  

};

/////CONTINUE HERE TO SE HOW TO ABSTRACT THE FILESYSTEM 03/08/2026

struct Brii_FS_CallStack
{
  Brii_FileSystemHandle* FS_handle{};
  void* struct_info{};
  BT_StringID_64 directoryID{};

};

class Brii_FileSystem_Manager
{
 private:

 std::vector<Brii_FS_CallStack> pile_Stack{};

 public:
 
	
 

};
