//
// Kregex.cpp for Kregex in /home/drozdz_b/Documents/Regex/CPP
//
// Made by drozdz_b
// Login   <drozdz_b@epitech.net>
//
// Started on  Sat Apr 16 20:00:03 2016 drozdz_b
// Last update Fri Jul  1 11:33:04 2016 drozdz_b
//

#include <cstdlib>

#include "Kregex.hh"

Kregex::Kregex()
{
  this->_reg_str = "";
  this->_pmatch = NULL;
  this->_nsub = 0;
}

Kregex::Kregex(const std::string& reg_str)
{
  this->_reg_str = reg_str;
  this->_pmatch = NULL;
  this->_nsub = 0;
  this->compile();
}

Kregex::~Kregex()
{
  regfree(&_preg);
}

void	Kregex::setRegexStr(const std::string& reg_str)
{
  this->_reg_str = reg_str;
}

int	Kregex::compile()
{
  int	ret;

  ret = regcomp(&_preg, this->_reg_str.c_str(), REG_EXTENDED);
  if (ret != 0)
    {
      regfree(&this->_preg);
      return (ret);
    }
  return (ret);
}

bool	Kregex::inside(const std::string& str)
{
  int	match;

  //std::cout << "str = " << str << std::endl;
  match = regexec(&_preg, str.c_str(), this->_nsub, this->_pmatch, 0);
  if (match == 0)
    return (true);
  else if (match == REG_NOMATCH)
    return (false);
  else
    return (false);
}

std::string	Kregex::extractOne(const std::string& str, std::string& rest)
{
  std::string		extr;
  size_t		size;
  size_t		start;

  _nsub++;
  _pmatch = new regmatch_t [_nsub];
  if (!this->inside(str.c_str()))
    return ("");
  start = this->_pmatch[0].rm_so;
  size = this->_pmatch[0].rm_eo - start;
  extr = str.substr(start, size);
  rest = str.substr(this->_pmatch[0].rm_eo, str.size() - size);
  delete [] _pmatch;
  return (extr);
}

std::vector<std::string>	Kregex::extract(const std::string& str)
{
  std::string			extr;
  std::string			rest;
  std::vector<std::string>	vect;

  extr = this->extractOne(str, rest);
  if(!extr.empty())
    vect.push_back(extr);
  while (!extr.empty())
    {
      extr = this->extractOne(rest, rest);
      if (!extr.empty())
	vect.push_back(extr);
    }
  return (vect);
}

Kregex	&Kregex::operator=(std::string const &reg_str)
{
  this->_reg_str = reg_str;
  this->compile();
  return (*this);
}

const std::string& Kregex::getStr() const
{
  return (_reg_str);
}

std::ostream& operator<<(std::ostream& os, const Kregex& kreg)
{
  os << kreg.getStr();
  return (os);
}