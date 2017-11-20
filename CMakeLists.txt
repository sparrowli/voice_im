# CMake minimum version
cmake_minimum_required (VERSION 2.8)

#
project (voice_im)

set (voice_im_VERSION_MAJOR 1)
set (voice_im_VERSION_MINOR 0)

include (${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
check_function_exists(pow HAVE_POW)
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

enable_testing()

add_test (test_run voice_im 2 10)

add_test (test_usage voice_im)
set_tests_properties(test_usage PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .* base exponent")

add_test (test_2_5 voice_im 2 5)
set_tests_properties(test_2_5 PROPERTIES PASS_REGULAR_EXPRESSION "is 32")


macro (do_test arg1 arg2 result)
  add_test (test_${arg1}_${arg2} voice_im ${arg1} ${arg2})
  set_tests_properties(test_${arg1}_${arg2} PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

do_test(5 2 "is 25")
do_test(10 5 "is 100000")
do_test(2 10 "is 1024")

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")


include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${voice_im_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${voice_im_VERSION_MINOR}")
include (CPack)
