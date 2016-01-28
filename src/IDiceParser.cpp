#include <dicenotation/interfaces/IDiceParser.h>

#include <dicenotation/DiceStruct.h>

DiceStruct * IDiceParser::createDiceStruct(int numberOfDices, int facesOfDice, bool modifier, int modifierValue)
{
	DiceStruct* dice = new DiceStruct();

	dice->numberOfDices = numberOfDices;
	dice->facesOfDice = facesOfDice;
	dice->modifier = modifier;
	dice->modifierValue = modifierValue;

	return dice;
}
