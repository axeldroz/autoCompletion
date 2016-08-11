//
// Parser.cpp for Parser in /home/drozdz_b/rendu/autoCompletion
// 
// Made by drozdz_b
// Login   <drozdz_b@epitech.net>
// 
// Started on  Fri Jul  1 14:01:05 2016 drozdz_b
// Last update Tue Jul  5 23:09:55 2016 drozdz_b
//

#include "Parser.hh"

Parser::Parser(const char* filename, ios_base::openmode mode)
: std::ifstream(filename, mode)
{
    _regCities = "[[:alpha:]À-ñ -\\'`’]+,{1}";
    _regNum = "[[:digit:]]+ *(bis)? +(allée|avenue|boulevard|chemin|impasse|place|rue|quai|square){1}";
    _regFullAddr = 
    "^[[:alpha:]À-ñ -\\'`’]+, ?[[:digit:]]+ ?(bis)? ? (allée|avenue|boulevard|chemin|impasse|place|rue|quai|square){1} ?[[:alpha:]]+[[:alpha:]À-ñ -\\'`’]+$";
}

Parser::~Parser()
{
}

bool Parser::lineIsValid(const std::string& str)
{
   return (_regFullAddr.inside(str));
   return (true);
}

void Parser::parse(std::map<std::string, std::map<std::string,
		   std::list<std::string> > >& nums, 
                   std::list<std::string>& cities, 
                   std::map<std::string, std::list<std::string> >& streetNames)
{
  std::string line;
  std::string city;
  std::string streetName;
  std::string num;    
    
  if(is_open())
    {
      while (std::getline((std::ifstream&)*this, line))
        {
	  if (!lineIsValid(line))
	    std::cerr << line << std::endl;
	  else
            {
	      city = _regCities.extractOne(line, line);
	      num = _regNum.extractOne(line, line);
	      streetName = line;
	      if (line[0] == ' ')
		streetName = line.substr(1, line.size() - 1);
	      cities.push_back(city);
	      streetNames[city].push_back(streetName + ' ');
	      nums[city][streetName].push_back(num);
            }
        }
    }
}

