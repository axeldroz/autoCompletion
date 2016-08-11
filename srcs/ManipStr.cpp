//
// ManipStr.cpp for ManipStr in /home/drozdz_b/rendu/autoCompletion
// 
// Made by drozdz_b
// Login   <drozdz_b@epitech.net>
// 
// Started on  Sat Jul  2 19:54:15 2016 drozdz_b
// Last update Tue Jul  5 22:07:54 2016 drozdz_b
//
#include "ManipStr.hh"

std::string ManipStr::toMaj(const std::string& str)
{
  std::locale loc;
  size_t i;
  std::string str2;
    
  i = 0;
  while (i < str.length())
    {
      str2 += std::toupper(str[i], loc);
      ++i;
    }
  return (str2);
}

std::string ManipStr::toMaj(char c)
{
  std::locale loc;
  std::string str;

  str = std::toupper(c, loc);
  return (str);
}

std::string ManipStr::toMin(const std::string& str)
{
  std::locale loc;
  size_t i;
  std::string str2;
    
  i = 0;
  while (i < str.length())
    {
      str2 += std::tolower(str[i], loc);
      ++i;
    }
  return (str2);
}

std::string ManipStr::toMin(char c)
{
  std::locale loc;
  std::string str;

  str = std::tolower(c, loc);
  return (str);
}

#include <iostream>

void ManipStr::replaceAll(std::vector<std::string>& vect, const std::string& s1,
const std::string& s2)
{
  std::vector<std::string>::iterator it;
  std::string tmp;
  size_t pos;
  size_t i;
  
  pos = 0;
  i = 0;
  it = vect.begin();
  while (it != vect.end())
  {
    (void)s1;
    tmp = *it;
    pos = (ManipStr::toMin(*it)).find(s1);
    //std::cout << "pos =" << pos << std::endl;
    vect[i] = (*it).replace(pos, s2.length(), s2);
   // std::cout << vect[i] << std::endl;
    ++it;
    ++i;
  }  
}
