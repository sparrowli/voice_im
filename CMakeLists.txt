# CMake minimum version
cmake_minimum_required (VERSION 2.8)

#
project (voice_im)

#
aux_source_directory(. DIR_SRCS)
#
add_executable(voice_im main.cc MathFunctions.cc)
#add_executable(voice_im ${DIR_SRCS})
