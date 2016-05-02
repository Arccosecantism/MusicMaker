#include "INIParser.hpp"

INIParser::INIParser()
{
}


INIParser::~INIParser()
{
}

void INIParser::readINI(const std::string& filename)
{
	try
	{
		boost::property_tree::read_ini(filename.c_str(), propTree);
	}
	catch (boost::property_tree::ini_parser::ini_parser_error E)
	{
		std::cout << "Fatal error: File with name " << filename << " does not exist.";
		exit(0);
	}

	/*for (auto& section : propTree)
	{
		std::cout << '[' << section.first << "]\n";
		for (auto& key : section.second)
			std::cout << key.first << "=" << key.second.get_value<std::string>() << "\n";
	}*/
}

void INIParser::setSection(const std::string& sname)
{
	sectionName = sname;
}



std::string INIParser::assemblePath(const std::string& key)
{
	if (sectionName == "")
	{
		return key;						//return key if there is not section name
	}
	else
	{
		return sectionName + "." + key;	//concatenate section name and key with period
	}
}