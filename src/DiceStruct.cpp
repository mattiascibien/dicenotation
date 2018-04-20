#include <dicenotation/DiceStruct.h>
#include <dicenotation/interfaces/IDiceRoller.h>

#include <stddef.h>

DiceStruct* DiceStruct::parse(IDiceParser* parser)
{
	return parser->parse();
}

int DiceStruct::roll(IDiceRoller * roller)
{
	int result = 0;
	for (size_t i = 0; i < numberOfDices; i++)
	{
		result += roller->roll(facesOfDice);
	}

	if (modifier) //TODO: can be better
	{
		result += modifierValue;
	}
	else
	{
		result -= modifierValue;
	}

	return result;
}
