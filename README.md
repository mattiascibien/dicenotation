# DiceNotation

[Standard Dice Notation](https://en.wikipedia.org/wiki/Dice_notation#Standard_notation) for C/C++.

## Usage

Include the header file for DiceNotation
```cpp
#include <DiceNotation.h>
```

You can then use the `rollDice(const char*)` function to roll a dice.
```cpp
int result = rollDice(2d10+5) + rollDice(1d6-2);
```

## Advanced Usage

It is possibile to customize the behavior of the library by extending the parser and the roller (see the classes: `IDiceRoller` `IDiceParser`)

## Building

At the moment only a Visual C++ 2015 solution is provided. The code is cross platform so you can include the `.h` and the `.cpp` in your source code to compile. Remember to add the `DICENOTATION_STATIC` definition to your compiler if you use a static library or embed the source code.

## Contributing

You are free to contribute the code to this repository. As soon as the first stable version is reached (0.1) the GitFlow branching model.
