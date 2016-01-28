#pragma once

//Do not define both DLL and static
#ifdef DICENOTATION_DLL
#undef DICENOTATION_STATIC
#endif

// Generic helper definitions for shared library support
#if defined _WIN32 || defined __CYGWIN__
#	define DICENOTATION_HELPER_DLL_IMPORT __declspec(dllimport)
#	define DICENOTATION_HELPER_DLL_EXPORT __declspec(dllexport)
#	define DICENOTATION_HELPER_DLL_LOCAL
#else
#	if __GNUC__ >= 4
#		define DICENOTATION_HELPER_DLL_IMPORT __attribute__ ((visibility ("default")))
#		define DICENOTATION_HELPER_DLL_EXPORT __attribute__ ((visibility ("default")))
#		define DICENOTATION_HELPER_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
#	else
#		define DICENOTATION_HELPER_DLL_IMPORT
#		define DICENOTATION_HELPER_DLL_EXPORT
#		define DICENOTATION_HELPER_DLL_LOCAL
#	endif
#endif

#ifndef DICENOTATION_STATIC // defined if DICENOTATION is compiled as a a static library
#	ifdef DICENOTATION_DLL_EXPORTS // defined if we are building the DICENOTATION DLL (instead of using it)
#		define DICENOTATION_API DICENOTATION_HELPER_DLL_EXPORT
#	else
#		define DICENOTATION_API DICENOTATION_HELPER_DLL_IMPORT
#		endif // DICENOTATION_DLL_EXPORTS
#	define DICENOTATION_LOCAL DICENOTATION_HELPER_DLL_LOCAL
#else // DICENOTATION_STATIC is defined: this means DICENOTATION is a static lib.
#	define DICENOTATION_API
#	define DICENOTATION_LOCAL
#endif // DICENOTATION_STATIC

#include <dicenotation/interfaces/IDiceParser.h>
#include <dicenotation/DiceStruct.h>

