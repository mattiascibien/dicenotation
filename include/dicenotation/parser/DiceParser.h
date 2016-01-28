#pragma once

#include <dicenotation/interfaces/IDiceParser.h>


#include <string>

class DiceStringParser : public IDiceParser
{
public:
	DiceStringParser(std::string str);
	~DiceStringParser();

	virtual DiceStruct* parse() override;

private:
	std::string m_str;

	const std::string m_regex_str = "([0-9]+)d([0-9]+)+(([+-])([0-9]+)){0,1}";
};
