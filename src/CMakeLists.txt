#include directories helps to include header files
include_directories(".")
include_directories(${INCLUDE_DIR})

#get the source filenames to compile
file(GLOB_RECURSE SOURCES *.cpp)

add_definitions("${CFLAGS}")
link_libraries("${LINK_LIBS}")

#creating object file list from the sources ignoring main file
foreach(filename ${SOURCES})
	list(APPEND OBJECTS ${filename})
endforeach(filename ${SOURCES})


add_library(${PRJ_NAME}-static STATIC ${OBJECTS})
#add_library(${PRJ_NAME}-shared SHARED ${OBJECTS})
