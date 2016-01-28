#include <dicenotation/DiceStruct.h>
#include <dicenotation/interfaces/IDiceRoller.h>

DiceStruct* DiceStruct::parse(IDiceParser* parser)
{
	return parser->parse();
}

int DiceStruct::roll(IDiceRoller * roller)
{
	return roller->roll();
}
