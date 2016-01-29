// ExampleConsole.cpp : Defines the entry point for the console application.
//

#include <DiceNotation.h>

#include <iostream>

#include "stdafx.h"


int main()
{
	std::cout << "Result is " << rollDice("3d5-4") << std::endl;
    return 0;
}

