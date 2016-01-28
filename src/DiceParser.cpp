#include <dicenotation/parser/DiceParser.h>

#include <regex>

DiceStringParser::DiceStringParser(std::string str)
{
	m_str = str;
}

DiceStringParser::~DiceStringParser()
{
}

DiceStruct* DiceStringParser::parse()
{
	std::regex rx(m_regex_str, std::regex_constants::ECMAScript);

	std::smatch result;
	std::regex_search(m_str, result, rx, std::regex_constants::match_continuous);

	int numberOfDices = stoi(result[0]);
	int facesOfDice = stoi(result[1]);
	int modifierValue = stoi(result[3]);
	bool modifier = result[2] == '+';
	
	return IDiceParser::createDiceStruct(numberOfDices, facesOfDice, modifier, modifierValue);
}

