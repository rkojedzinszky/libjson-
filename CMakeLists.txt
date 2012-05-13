
cmake_minimum_required (VERSION 2.8)
project (libjson++)

execute_process(
		COMMAND sh -c "git describe --tags HEAD | sed -e 's/\\..*//'"
		WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
		OUTPUT_VARIABLE libjson++_VERSION_MAJOR
		OUTPUT_STRIP_TRAILING_WHITESPACE
)
execute_process(
		COMMAND sh -c "git describe --tags HEAD | sed -e 's/-.*//'"
		WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
		OUTPUT_VARIABLE libjson++_VERSION_FULL
		OUTPUT_STRIP_TRAILING_WHITESPACE
)

if ( "${CMAKE_BUILD_TYPE}" STREQUAL "" )
	set ( CMAKE_BUILD_TYPE Release )
endif ( )

set (CMAKE_C_FLAGS "-Wall -Wextra -Werror")
set (CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

include_directories("${PROJECT_SOURCE_DIR}/include")

add_subdirectory(include)
add_subdirectory(src)

