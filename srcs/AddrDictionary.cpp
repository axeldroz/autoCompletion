//
// AddrDictionary.cpp for AddrDictionary in /home/drozdz_b/rendu/autoCompletion/srcs
// 
// Made by drozdz_b
// Login   <drozdz_b@epitech.net>
// 
// Started on  Tue Jul  5 23:09:19 2016 drozdz_b
// Last update Tue Jul  5 23:09:20 2016 drozdz_b
//

#include "AddrDictionary.hh"

AddrDictionary::AddrDictionary() : StrDictionary()
{
}

void AddrDictionary::init(const std::map<std::string,
			     std::map<std::string, std::list<std::string> > >& num, 
			     const std::list<std::string>& cities,
			     const std::map<std::string,
			     std::list<std::string> >& street)
{
  _nums = num;
  _streetNames = street;
  _cities = cities;
}

const std::string& AddrDictionary::getString(const std::list<std::string>& list,
					     int i)
{
  std::list<std::string>::const_iterator it;
  
  it = list.begin();
  while (it != list.end())
    {
      if (i <= 1)
	    return (*it);
      --i;
      ++it;     
    }
  throw MyException("Invalid argument");
}

std::ostream& AddrDictionary::dispFullAddr(std::ostream& out, std::istream& in,
					   std::string city, std::string street)
{
  std::list<std::string> list = _nums[city + ','][street];
  std::list<std::string>::iterator it;
  size_t i;
    
  if (list.size() == 1)
    {
      out << "=> " << city << ", " << list.front() << " " << street << std::endl; 
      return(out);                
    }        
  it = list.begin();
  i = 1;
  while (it != list.end())
    {
      out << "{" << i << " : " << city << ", " << *it << " " << street << "}";
      ++it;
      if (it != list.end())
	    out << " ";
      ++i;
    }
  out << std::endl;
  in >> i;
  if (i < 1 || i > list.size())
    throw MyException("Invalid argument");
  out << "=> " << city << ", " << getString(list, i) << " " << street << std::endl;
  return (out);
}
std::string AddrDictionary::searching(std::istream& in, std::ostream& out)
{
  std::string city;
  std::string street;
  std::string num;
  std::string tmp;
    
  tmp = "";   
  fill(_cities);
  city = StrDictionary::searching(in, out, tmp);
  fill(_streetNames[city + ','], true);
  tmp += ", ";
  street = StrDictionary::searching(in, out, tmp);
  dispFullAddr(out, in, city, street);
  return ("");
}
