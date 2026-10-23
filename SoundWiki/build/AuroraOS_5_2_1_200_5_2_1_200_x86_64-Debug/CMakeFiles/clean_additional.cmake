# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/ru.ac.uniyar.SoundWiki_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/ru.ac.uniyar.SoundWiki_autogen.dir/ParseCache.txt"
  "ru.ac.uniyar.SoundWiki_autogen"
  )
endif()
