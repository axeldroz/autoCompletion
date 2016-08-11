//
// AutoCompletion.hh for AutoCompletion in /home/drozdz_b/rendu/autoCompletion
// 
// Made by drozdz_b
// Login   <drozdz_b@epitech.net>
// 
// Started on  Sat Jul  2 19:01:17 2016 drozdz_b
// Last update Tue Jul  5 22:11:28 2016 drozdz_b
//

#ifndef AUTOCOMPLETION_HH_
#define AUTOCOMPLETION_HH_

#include <ostream>
#include <istream>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include "CharTree.hh"
#include "Kregex.hh"
#include "Parser.hh"
#include "AddrDictionary.hh"
#include "ManipStr.hh"

class AutoCompletion
{
private:
  AddrDictionary	_dico;
public:
  void	goCity(std::istream& in, std::ostream& out);
  void	getAddresses(const std::string& filename);
};

#endif
