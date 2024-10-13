# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TerMax_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TerMax_autogen.dir\\ParseCache.txt"
  "TerMax_autogen"
  )
endif()
