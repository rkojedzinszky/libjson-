
cmake_minimum_required (VERSION 2.8)
project (libjson++)

set (libjson++_VERSION_MAJOR 0)
set (libjson++_VERSION_MINOR 3)
set (libjson++_VERSION_PATCH 1)

if ( "${CMAKE_BUILD_TYPE}" STREQUAL "" )
	set ( CMAKE_BUILD_TYPE Release )
endif ( )

set (CMAKE_C_FLAGS "-Wall -Wextra -Werror")
set (CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

include_directories("${PROJECT_SOURCE_DIR}/include")

add_subdirectory(include)
add_subdirectory(src)

