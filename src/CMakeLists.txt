set(json_SOURCES
		iarray
		ibool
		inumeric
		iobject
		istring
		ivalue
		util
		value
   )

add_library(jsonstatic STATIC ${json_SOURCES})
add_library(jsonshared SHARED ${json_SOURCES})

set_target_properties (jsonstatic PROPERTIES OUTPUT_NAME json++)
set_target_properties (jsonshared PROPERTIES OUTPUT_NAME json++
		VERSION ${libjson++_VERSION_MAJOR}.${libjson++_VERSION_MINOR}.${libjson++_VERSION_PATCH}
		SOVERSION ${libjson++_VERSION_MAJOR}.${libjson++_VERSION_MINOR}
)

install(TARGETS
		jsonstatic
		jsonshared
		DESTINATION lib)
