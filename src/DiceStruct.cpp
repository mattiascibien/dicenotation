#include <dicenotation/DiceStruct.h>

DiceStruct* DiceStruct::parse(IDiceParser* parser)
{
	return parser->parse();
}

int DiceStruct::roll()
{
	return 0;
}
