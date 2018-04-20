cmake_minimum_required(VERSION 3.5)
project(dicenotation VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(ENABLE_TESTS "Enables the test" 0)

add_library(dicenotation
	src/DiceNotation.cpp
	src/DiceParser.cpp
	src/DiceStruct.cpp
	src/IDiceParser.cpp
	src/StdRandomRoller.cpp
)

if ( NOT BUIILD_SHARED_LIBS )
	add_definitions( -DDICENOTATION_STATIC )
endif()

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

if(ENABLE_TESTS)
	enable_testing()

	find_package(Boost COMPONENTS unit_test_framework REQUIRED)

	#I like to keep test files in a separate source directory called test
	file(GLOB TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} tests/*.cpp)

	#Run through each source
	foreach(testSrc ${TEST_SRCS})
			#Extract the filename without an extension (NAME_WE)
			get_filename_component(testName ${testSrc} NAME_WE)

			#Add compile target
			add_executable(${testName} ${testSrc})

			target_include_directories (${testName} PRIVATE ${Boost_INCLUDE_DIRS})

			#link to Boost libraries AND your targets and dependencies
			target_link_libraries(${testName} ${Boost_LIBRARIES} DiceNotation::dicenotation)

			#I like to move testing binaries into a testBin directory
			set_target_properties(${testName} PROPERTIES 
				RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/testBin)

			#Finally add it to test execution - 
			#Notice the WORKING_DIRECTORY and COMMAND
			add_test(NAME ${testName} 
					WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/testBin 
					COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/testBin/${testName} )
	endforeach(testSrc)
endif()