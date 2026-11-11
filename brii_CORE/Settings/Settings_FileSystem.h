#pragma once 

#include "dataManager/dataTypes_brii.h"


enum class Brii_FS_OpenFlags : BT_ios_openFlags
{
 EMPTY = 0,
 BRII_CREATE_FILE = 1,
 BRII_WRITE_ONLY = 1 << 1,
 BRII_READ_ONLY = 1 << 2,
 BRII_READ_AND_WRITE = 1 << 3,
 BRII_BINARY = 1 << 4, ///used by the cpp standard <fstream>, to open in binary mode
 BRII_TRUNC = 1 << 5
};

template<> inline constexpr bool is_bitmask_flag<Brii_FS_OpenFlags> = true;

enum class Brii_FS_Permissions : BT_ios_openPermFlags
{ 
  EMPTY = 0,

  BRII_USER_READ = 1,
  BRII_USER_WRITE = 1 << 1,
  BRII_USER_EXECUTABLE = 1 << 2, 
 
  BRII_GROUP_READ = 1 << 3,
  BRII_GROUP_WRITE = 1 << 4,
  BRII_GROUP_EXECUTABLE = 1 << 5,
  
  BRII_OTHER_G_READ = 1 << 6,
  BRII_OTHER_G_WRITE = 1 << 7,
  BRII_OTHER_G_EXECUTABLE = 1 << 8,
  ///THIS PERMISSIONS HAVE A BIGGER JERAQUIA
  ///WinAPI only use this
  BRII_STANDARD = 
  BRII_USER_READ | BRII_USER_WRITE | 
  BRII_GROUP_READ | BRII_OTHER_G_READ,

  BRII_EXECUTABLE_ARCHIVE = 
  BRII_USER_WRITE | BRII_USER_WRITE | BRII_USER_EXECUTABLE |
  BRII_GROUP_READ | BRII_GROUP_EXECUTABLE |
  BRII_OTHER_G_READ | BRII_OTHER_G_EXECUTABLE
};

template<> inline constexpr bool is_bitmask_flag<Brii_FS_Permissions> = true;

enum class Brii_FS_errors : BT_ios_errorFlags
{ 
  BRII_ERROR_WRITE_FILE = 1,
  BRII_ERROR_WRITE_BYTES_MATCH = 1 << 1,
  
  BRII_ERROR_READ_FILE = 1 << 2,
  BRII_ERROR_READ_BYTES_MATCH = 1 << 3,
  
  BRII_ERROR_OPEN_FILE = 1 << 4,
  BRII_ERROR_TRUNCATE_BYTES = 1 << 5
 
};

template<> inline constexpr bool is_bitmask_flag<Brii_FS_errors> = true;


namespace BF_Ios
{

////FLAGS OPENMODE used by open_file()

using openMode = Brii_FS_OpenFlags;

///Used to create the file if not exists
inline constexpr openMode o_empty = openMode::EMPTY;
inline constexpr openMode o_createF = openMode::BRII_CREATE_FILE;
inline constexpr openMode o_writeF = openMode::BRII_WRITE_ONLY;
inline constexpr openMode o_readF = openMode::BRII_READ_ONLY;
inline constexpr openMode o_rwF = openMode::BRII_READ_AND_WRITE;
inline constexpr openMode o_binary = openMode::BRII_BINARY;
inline constexpr openMode o_truncF = openMode::BRII_TRUNC;

//////////////////////////////////////////////////////////////////////////
//FLAGS PERSMISSIONS used by open_file()

using openPermissions = Brii_FS_Permissions;

inline constexpr openPermissions op_empty = openPermissions::EMPTY;
inline constexpr openPermissions op_standard = openPermissions::BRII_STANDARD;
inline constexpr openPermissions op_executable_archive = openPermissions::BRII_EXECUTABLE_ARCHIVE;

/////////////////////////////////////////////////////////////////////////
///FLAGS for errors in FS

using error_FS = Brii_FS_errors;

inline constexpr error_FS error_write_file= error_FS::BRII_ERROR_WRITE_FILE;
inline constexpr error_FS error_write_bytes_match = error_FS::BRII_ERROR_WRITE_BYTES_MATCH;

inline constexpr error_FS error_read_file = error_FS::BRII_ERROR_READ_FILE;
inline constexpr error_FS error_read_bytes_match = error_FS::BRII_ERROR_READ_BYTES_MATCH;

inline constexpr error_FS error_open_file = error_FS::BRII_ERROR_OPEN_FILE;
inline constexpr error_FS error_truncate_bytes = error_FS::BRII_ERROR_TRUNCATE_BYTES;

}


enum class Brii_FS_Category
{
 BRII_LOG = 1,
 BRII_STRING_FILE = 1 << 1
};





