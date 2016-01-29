#include <DiceNotation.h>

#include <dicenotation/parser/DiceParser.h>
#include <dicenotation/roller/StdRandomRoller.h>

int rollDice(const char* string)
{
	IDiceParser *parser = new DiceStringParser(string);
	IDiceRoller *roller = new StdRandomRoller();
	DiceStruct* dicestruct = DiceStruct::parse(parser);

	int result = dicestruct->roll(roller);

	delete parser;
	delete roller;
	delete dicestruct;

	return result;
}