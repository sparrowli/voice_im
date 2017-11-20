# CMake minimum version
cmake_minimum_required (VERSION 2.8)

#
project (voice_im)

configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

option  (USE_MYMATH
        "Use provided math implementation" ON)

if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/math")
  add_subdirectory (math)
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)

#
aux_source_directory(. DIR_SRCS)
#
add_executable(voice_im main.cc)

target_link_libraries(voice_im ${EXTRA_LIBS})
#add_executable(voice_im ${DIR_SRCS})


install (TARGETS voice_im DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/config.h" DESTINATION include)
