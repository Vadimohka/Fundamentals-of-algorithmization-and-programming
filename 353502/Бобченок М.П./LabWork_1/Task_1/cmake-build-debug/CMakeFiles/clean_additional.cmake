# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/telega_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/telega_autogen.dir/ParseCache.txt"
  "telega_autogen"
  )
endif()
