# CMake minimum version
cmake_minimum_required (VERSION 2.8)

#
project (voice_im)

#
aux_source_directory(. DIR_SRCS)
#
add_subdirectory(math)

add_executable(voice_im main.cc)

target_link_libraries(voice_im MathFunctions)
#add_executable(voice_im ${DIR_SRCS})
