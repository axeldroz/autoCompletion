//
// Kregex.hpp for Kregex in /home/drozdz_b/Documents/Regex/CPP
//
// Made by drozdz_b
// Login   <drozdz_b@epitech.net>
//
// Started on  Sat Apr 16 19:59:03 2016 drozdz_b
// Last update Sat Apr 23 19:08:11 2016 Anaïs Foncel
//

#ifndef KREGEX_HH_
# define KREGEX_HH_

# include <iostream>
# include <ostream>
# include <string>
# include <vector>
# include <regex.h>
# include <cstdlib>

class Kregex
{
private:
  std::string	_reg_str;
  regex_t	_preg;
  regmatch_t	*_pmatch;
  size_t       	_nsub;

public:
  Kregex();
  Kregex(const std::string& reg_str);
  Kregex(const std::string& reg_str, const std::string& str);
  ~Kregex();

  void	setRegexStr(const std::string& reg_str);

  int  		compile();
  bool	       	inside(const std::string& str);
  std::string	extractOne(const std::string& str, std::string& rest);
  std::vector<std::string>	extract(const std::string&);
  const std::string& getStr() const;

  Kregex	&operator=(std::string const &reg_str);
};

std::ostream& operator<<(std::ostream& os, const Kregex& kreg);


#endif
