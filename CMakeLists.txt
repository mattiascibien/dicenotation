cmake_minimum_required(VERSION 2.6)

#set project name
set(PRJ_NAME DiceNotation)

#libraries to link
set(LINK_LIBS "")
#define cflags
set(CFLAGS "")
#define header include directories as list
set(INCLUDE_DIR "include")

project(${PRJ_NAME})

include_directories(${INCLUDE_DIR})
add_subdirectory(src)
#add_subdirectory(tests)

#set enable testing
#enable_testing()