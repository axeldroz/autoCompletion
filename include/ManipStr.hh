//
// ManipStr.hh for ManipStr in /home/drozdz_b/rendu/autoCompletion
// 
// Made by drozdz_b
// Login   <drozdz_b@epitech.net>
// 
// Started on  Sat Jul  2 19:54:02 2016 drozdz_b
// Last update Tue Jul  5 22:01:53 2016 drozdz_b
//

#ifndef MANIPSTR_HH_
#define MANIPSTR_HH_

#include <string>
#include <locale>
#include <vector>
namespace ManipStr
{
  std::string	toMaj(const std::string& str);
  std::string	toMaj(char c);
  std::string	toMin(const std::string& str);
  std::string	toMin(char c);
  void replaceAll(std::vector<std::string>& vect, const std::string& s1, 
  const std::string& s2);
}

#endif
