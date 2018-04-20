# DiceNotation [![Build Status](https://travis-ci.org/mattiascibien/DiceNotation.svg?branch=master)](https://travis-ci.org/mattiascibien/DiceNotation)

[Standard Dice Notation](https://en.wikipedia.org/wiki/Dice_notation#Standard_notation) for C/C++.

## Usage

Include the header file for DiceNotation
```cpp
#include <DiceNotation.h>
```

You can then use the `rollDice(const char*)` function to roll a dice.
```cpp
int result = rollDice("2d10+5") + rollDice("1d6-2");
```

## Advanced Usage

It is possibile to customize the behavior of the library by extending the parser and the roller (see the classes: `IDiceRoller` `IDiceParser`)

## Building

In order to build the solution `cmake >= 3.5` is required to build the solution. The option `BUILD_SHARED_LIBS` determines wether a shared (DLL on Windows) or static library is built.

It is also possible to drop the `.cpp` and `.h` files alongside your existing source code (be sure to define `DICENOTATION_STATIC` in your compile options).

The library is being tested on the following compilers:

 * Visual C++ 2017
 * GCC
 * Clang

## Contributing

You are free to contribute the code to this repository. As soon as the first stable version is reached (0.1) the GitFlow branching model will be adopted.
