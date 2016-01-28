#pragma once

#ifdef DICENOTATION_STATIC
#	define DICENOTATION_API 
#else
#	ifdef DICENOTATION_EXPORTS
#		define DICENOTATION_API _declspec(dllexport)
#	else
#		define DICENOTATION_API _declspec(dllimport)
#	endif
#endif

#include <dicenotation/interfaces/IDiceParser.h>
#include <dicenotation/DiceStruct.h>

