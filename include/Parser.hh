//
// Parser.hh for Parser in /home/drozdz_b/rendu/autoCompletion
// 
// Made by drozdz_b
// Login   <drozdz_b@epitech.net>
// 
// Started on  Fri Jul  1 14:01:01 2016 drozdz_b
// Last update Tue Jul  5 22:03:43 2016 drozdz_b
//

#ifndef _PARSER_HH_
#define _PARSER_HH_

#include <fstream>
#include <list>
#include <string>
#include <map>

#include "Kregex.hh"

class Parser : public std::ifstream
{
private:
    Kregex	_regCities;
    Kregex	_regNum;
    Kregex	_regFullAddr;
  
public:
    Parser(const char* filename, ios_base::openmode mode = ios_base::in);
    ~Parser();
    
    bool	lineIsValid(const std::string& str);
    void	parse(std::map<std::string,
		      std::map<std::string, std::list<std::string> > >& nums, 
		      std::list<std::string>& cities, 
		      std::map<std::string, std::list<std::string> >& streetNames);
};

#endif
