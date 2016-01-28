#pragma once

class DiceStruct;

class IDiceParser
{
protected:
	DiceStruct* createDiceStruct(int numberOfDices,	int facesOfDice, bool modifier, int modifierValue);
public:
	virtual DiceStruct* parse() = 0;
};
