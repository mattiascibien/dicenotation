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

class DiceStruct;

/// <summary>
/// Interface for implementing a parser. Derived classes must implement the parse() method.
/// </summary>
class IDiceParser
{
protected:
	/// <summary>
	/// Creates the dice structure. It is used by derived classes to construct a DiceStruct, which has a private constructor
	/// </summary>
	/// <param name="numberOfDices">The number of dices.</param>
	/// <param name="facesOfDice">The faces of dice.</param>
	/// <param name="modifier">if set to <c>true</c> [modifier].</param>
	/// <param name="modifierValue">The modifier value.</param>
	/// <returns></returns>
	virtual DiceStruct* createDiceStruct(int numberOfDices, int facesOfDice, bool modifier, int modifierValue) final;
public:
	/// <summary>
	/// Parses a instance.
	/// </summary>
	/// <returns>The parsed DiceStruct</returns>
	virtual DiceStruct* parse() = 0;
};
