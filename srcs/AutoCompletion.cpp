//
// AutoCompletion.cpp for AutoCompletion in /home/drozdz_b/rendu/autoCompletion
// 
// Made by drozdz_b
// Login   <drozdz_b@epitech.net>
// 
// Started on  Sat Jul  2 19:01:34 2016 drozdz_b
// Last update Tue Jul  5 22:08:17 2016 drozdz_b
//

#include "AutoCompletion.hh"

void AutoCompletion::getAddresses(const std::string& filename)
{
  std::map<std::string, std::map<std::string, std::list<std::string> > > nums;
  std::list<std::string> cities;
  std::map<std::string, std::list<std::string> > streetNames;
  Parser parser(filename.c_str());
    
  parser.parse(nums, cities, streetNames);
  _dico.init(nums, cities, streetNames);
  _dico.fill(cities);
}

void AutoCompletion::goCity(std::istream& in, std::ostream& out)
{
  _dico.searching(in, out);
}
