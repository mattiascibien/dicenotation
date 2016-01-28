#pragma once

#ifdef DICENOTATION_STATIC
#	define DICENOTATION_API 
#else
#	if defined(_MSC_VER)
#		ifdef DICENOTATION_EXPORTS
#			define DICENOTATION_API _declspec(dllexport)
#		else
#			define DICENOTATION_API _declspec(dllimport)
#		endif
#	elif defined(_GCC)
#		ifdef DICENOTATION_EXPORTS
#			define DICENOTATION_API __attribute__((visibility("default")))
#		else
#			define DICENOTATION_API
#		endif
#	else
#		define DICENOTATION_API
#		pragma warning Unknown dynamic link import/export semantics.
#	endif
#endif

#include <dicenotation/interfaces/IDiceParser.h>
#include <dicenotation/DiceStruct.h>

