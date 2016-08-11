/*
** AddrDictionary.hh for AddrDictionary in /home/drozdz_b/rendu/autocompletion
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Thu Jun 30 09:41:53 2016 drozdz_b
// Last update Tue Jul  5 22:12:15 2016 drozdz_b
*/

#ifndef ADDRDICTIONARY_HH_
#define ADDRDICTIONARY_HH_

#include "StrDictionary.hh"

class AddrDictionary : public StrDictionary
{
private:
  std::map<std::string, std::map<std::string,
			      std::list<std::string> > >	_nums;
  std::list<std::string>					_cities;
  std::map<std::string, std::list<std::string> >		_streetNames;
  
public:
  AddrDictionary();
  void	init(const std::map<std::string,
	     std::map<std::string, std::list<std::string> > >& num, 
	     const std::list<std::string>& cities, 
	     const std::map<std::string, std::list<std::string> >& street);

  std::string		searching(std::istream& in, std::ostream& out);

private:
  const	std::string&	getString(const std::list<std::string>& list, int i);
  std::ostream&		dispFullAddr(std::ostream& out, std::istream& in,
				     std::string city, std::string street);
};

#endif
