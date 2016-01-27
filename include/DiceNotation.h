#pragma once

#ifdef DICENOTATION_STATIC
#	define DICENOTATION_API 
#else
#	ifdef DICENOTATION_EXPORTS
#		define DICENOTATION_API __cdecl(dllexport)
#	else
#		define DICENOTATION_API __cdecl(dllimport)
#	endif
#endif

#include <dicenotation/DiceStruct.h>