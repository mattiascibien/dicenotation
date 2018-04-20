cmake_minimum_required(VERSION 3.5)
project(dicenotation VERSION 1.0.0 LANGUAGES CXX)

add_library(dicenotation
	src/DiceNotation.cpp
	src/DiceParser.cpp
	src/DiceStruct.cpp
	src/IDiceParser.cpp
	src/StdRandomRoller.cpp
)

if ( )

add_library(DiceNotation::dicenotation ALIAS dicenotation)

target_include_directories(dicenotation
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
)

include(GNUInstallDirs)

install(TARGETS dicenotation
	EXPORT dicenotation-targets
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)


set_target_properties(dicenotation PROPERTIES EXPORT_NAME DiceNotation)
