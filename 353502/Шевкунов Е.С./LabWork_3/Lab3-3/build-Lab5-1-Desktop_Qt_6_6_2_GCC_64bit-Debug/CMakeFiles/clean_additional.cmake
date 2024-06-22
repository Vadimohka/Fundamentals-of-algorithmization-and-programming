# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Lab5-1_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Lab5-1_autogen.dir/ParseCache.txt"
  "Lab5-1_autogen"
  )
endif()
