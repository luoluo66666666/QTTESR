# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\serial_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\serial_autogen.dir\\ParseCache.txt"
  "serial_autogen"
  )
endif()
