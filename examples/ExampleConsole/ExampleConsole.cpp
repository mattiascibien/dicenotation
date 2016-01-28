// ExampleConsole.cpp : Defines the entry point for the console application.
//

#include <DiceNotation.h>
#include <dicenotation/parser/DiceParser.h>

#include "stdafx.h"


int main()
{
	IDiceParser *parser = new DiceStringParser("1d5+1");
	DiceStruct* test = DiceStruct::parse(parser);
    return 0;
}

