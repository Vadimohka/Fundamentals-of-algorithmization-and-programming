# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/LabWork_5_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/LabWork_5_autogen.dir/ParseCache.txt"
  "CMakeFiles/Task2_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Task2_autogen.dir/ParseCache.txt"
  "LabWork_5_autogen"
  "Task2_autogen"
  )
endif()
