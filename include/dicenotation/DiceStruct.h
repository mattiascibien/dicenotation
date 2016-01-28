#pragma once

#include <DiceNotation.h>

class IDiceParser;

class DICENOTATION_API DiceStruct
{
	friend class IDiceParser;
public:
	static DiceStruct* parse(IDiceParser* parser);

	int roll();
private:
	DiceStruct() { }

	int numberOfDices;
	int facesOfDice;
	bool modifier;
	int modifierValue;
};