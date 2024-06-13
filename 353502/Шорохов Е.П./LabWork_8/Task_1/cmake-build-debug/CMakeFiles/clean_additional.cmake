# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Heap_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Heap_autogen.dir/ParseCache.txt"
  "CMakeFiles/LabWork_8_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/LabWork_8_autogen.dir/ParseCache.txt"
  "Heap_autogen"
  "LabWork_8_autogen"
  )
endif()
