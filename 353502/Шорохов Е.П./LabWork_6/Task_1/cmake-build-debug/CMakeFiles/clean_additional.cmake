# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/LabWork_6_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/LabWork_6_autogen.dir/ParseCache.txt"
  "CMakeFiles/Task2_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Task2_autogen.dir/ParseCache.txt"
  "LabWork_6_autogen"
  "Task2_autogen"
  )
endif()
