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
	DiceStruct *returnValue = nullptr;
	std::regex rx(m_regex_str, std::regex_constants::ECMAScript);

	std::smatch result;
	if (std::regex_match(m_str, result, rx, std::regex_constants::match_continuous))
	{
		std::ssub_match match = result[0];

		int numberOfDices = stoi(result[1].str());
		int facesOfDice = stoi(result[2].str());
		int modifierValue = stoi(result[4].str());
		bool modifier = result[3].str() == "+";

		IDiceParser::createDiceStruct(numberOfDices, facesOfDice, modifier, modifierValue);
	}
	
	return returnValue; 
}

