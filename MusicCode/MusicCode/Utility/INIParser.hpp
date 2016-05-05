#pragma once
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost\lexical_cast.hpp>
#include <iostream>

class INIParser
{
public:
	INIParser();
	~INIParser();
	void readINI(const std::string& filename);
	void setDirectory(const std::string& dname);
	void setSection(const std::string& sname);


	template<typename T>
	void readValue(const std::string& keystr, T& typeInst)
	{
		boost::optional<T> op = propTree.get_optional<T>(assemblePath(keystr)); //returns uninitialized boost::optional object if value != exist

		if (op)
		{
			typeInst = *op;
		}
		else
		{
			std::cout << keystr << " was not found in " << sectionName << "." << std::endl;
		}
	}


	template<class T>
	T getValue(const std::string& keystr)	//takes a string and return its value loaded from INI
	{
		//tree.get would throw ptree_bad_path (ptree_error) on nonexistent value
		boost::optional<T> op = propTree.get_optional<T>(assemblePath(keystr)); //returns uninitialized boost::optional object if value != exist

		if (op)
		{
			return *op;
		}
		else
		{
			std::cout << keystr << " was not found in " << sectionName << "." << std::endl;
		}
	}

private:

	std::string assemblePath(const std::string& key);

	boost::property_tree::ptree propTree;
	std::string directoryName;
	std::string sectionName;

};

