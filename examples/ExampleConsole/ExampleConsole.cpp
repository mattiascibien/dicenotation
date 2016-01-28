// ExampleConsole.cpp : Defines the entry point for the console application.
//

#include <DiceNotation.h>
#include <dicenotation/parser/DiceParser.h>
#include <dicenotation/roller/StdRandomRoller.h>

#include <iostream>

#include "stdafx.h"


int main()
{
	IDiceParser *parser = new DiceStringParser("3d5-4");
	IDiceRoller *roller = new StdRandomRoller();
	DiceStruct* test = DiceStruct::parse(parser);
	std::cout << "Result is " << test->roll(roller) << std::endl;
    return 0;
}

