# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "RelWithDebInfo")
  file(REMOVE_RECURSE
  "AWL_autogen"
  "CMakeFiles/AWL_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/AWL_autogen.dir/ParseCache.txt"
  "CMakeFiles/Hash_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Hash_autogen.dir/ParseCache.txt"
  "CMakeFiles/LabWork_7_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/LabWork_7_autogen.dir/ParseCache.txt"
  "Hash_autogen"
  "LabWork_7_autogen"
  )
endif()
