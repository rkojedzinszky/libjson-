
cmake_minimum_required (VERSION 2.8)
project (libjson++)

set (libjson++_VERSION_MAJOR 1)
set (libjson++_VERSION_MINOR 1)
set (libjson++_VERSION_PATCH 0)

if ( "${CMAKE_BUILD_TYPE}" STREQUAL "" )
	set ( CMAKE_BUILD_TYPE Release )
endif ( )

if (${UNIX})
	set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
endif ()

include_directories("${PROJECT_SOURCE_DIR}/include")

add_subdirectory(include)
add_subdirectory(src)

