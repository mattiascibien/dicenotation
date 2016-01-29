// Copyright(c) 2016 Mattias Cibien
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

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
#include <dicenotation/interfaces/IDiceRoller.h>
#include <dicenotation/DiceStruct.h>

namespace DiceNotation
{
	/// <summary>
	/// Rolls the dice specified in standard dice notation.
	/// </summary>
	/// <param name="string">The string in standard dice notation.</param>
	/// <returns></returns>
	int rollDice(const char* string);
}