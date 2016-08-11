//
// StrDictionary.cpp for StrDictionary in /home/drozdz_b/rendu/autoCompletion
// 
// Made by drozdz_b
// Login   <drozdz_b@epitech.net>
// 
// Started on  Sun Jul  3 15:56:36 2016 drozdz_b
// Last update Tue Jul  5 23:10:32 2016 drozdz_b
//

#include "StrDictionary.hh"
#include <iostream>

void StrDictionary::fill(const std::list<std::string>& list)
{
  _tree.addWordList(list);
}

void StrDictionary::fill(const std::list<std::string>& list, bool b)
{
  if (b)
    {
      _tree.removeTree();
      _tree.alloc();
    }
  _tree.addWordList(list);
}

void StrDictionary::possibilities(const std::string& preced, std::vector<CharNode*>& nodes)
{
  std::vector<CharNode*>::iterator it;
  std::string tmp;
  size_t i;
    
  it = nodes.begin();
  i = 0;
  _prop.clear();
  while (it != nodes.end() && i < 5)
    {
      tmp = ManipStr::toMaj(preced) + (*it)->data;
      _prop.push_back(tmp);
      ++it;
      ++i;
    }
}

// void StrDictionary::possibilities2(const std::string& preced, std::vector<CharNode*>& nodes)
// {
//   std::vector<CharNode*>::iterator it;
//   std::string tmp;
//   size_t i;
    
//   it = nodes.begin();
//   i = 0;
//   _prop.clear();
//   while (it != nodes.end() && i < 5)
//     {
//       tmp = ManipStr::toMaj(preced) + (*it)->data;
//       _prop.push_back(tmp);
//       ++it;
//       ++i;
//     }
// }

void StrDictionary::fullPossibilities(CharNode* node)
{
  std::list<std::string*>::iterator it;
  std::string tmp;
  size_t i;
    
  it = node->ptrList.begin();
  i = 0;
  _propfull.clear();
  while (it != node->ptrList.end() && i < 5)
  {
    // std::cout << "prop = " << _prop[i] << std::endl;
    if (*it != NULL)
    {
	    tmp = (**it);
      _propfull.push_back(tmp);
    }
    ++it;
    ++i;
  }
}

CharNode* StrDictionary::getAskedPos(CharNode* node, std::string& preced, char c)
{
  size_t i;
  std::vector<CharNode*> vect;
  std::vector<CharNode*>::iterator it;
  std::locale loc;

  if (node == NULL)
    node = _tree.getRoot();
  if (c == 0)
    return (node);
  vect = _tree.getNextPos(node);
  it = vect.begin();    
  i = 0;
  c = std::tolower(c, loc);
  while (it != vect.end())
  {
    if ((*it)->data == c)
    {
	    if (i < 5 && _prop.size() < i)
	      preced = ManipStr::toMaj(_prop[i]);
	    else
	      preced = ManipStr::toMaj(c);
      _fullpreced += ManipStr::toMaj(c);
	    return (*it);
    }
    ++it;
    ++i;
  }
  return (NULL); 
}

std::ostream& StrDictionary::dispProp(std::ostream& os)
{
  std::vector<std::string>::iterator it;
    
  it = _prop.begin();
  while (it != _prop.end())
    {
      os << "{" << *it << "}";
      if ((it + 1) != _prop.end())
	os << ' ';
      ++it;
    }
  return (os);
}

std::ostream& StrDictionary::dispPropFull(std::ostream& os)
{
  int i;
  std::vector<std::string>::iterator it;
    
  i = 0;
  it = _propfull.begin();
  while (it != _propfull.end())
    {
      os << "{";
      if (_propfull.size() > 1)
        os << i + 1 << " : ";
      os << *it << "}";
      if (it + 1 != _propfull.end())
        os << ' ';
      ++it;
      ++i;
    }
  return (os);
}

std::vector<std::string> StrDictionary::getPropFull() const
{
  return (_propfull);
}

CharNode* StrDictionary::search(std::string& preced, CharNode* node, char c)
{
  std::vector<CharNode*> vect;
  std::vector<CharNode*>::iterator it;
    
  node = getAskedPos(node, preced, c);
  if (node == NULL)
    throw MyException("Unknow address");
  if (node->children.size() == 1 && node->countPrefix > 0 && node->countWord == 0)
    {
      _prop = std::vector<std::string>();
      vect = _tree.getNextPos(node);
      possibilities(preced, vect);
      return (search(preced, node, node->children[0]->data));
    }
  else if (node->children.size() > 0)
    {
      vect = _tree.getNextPos(node);
      if (node->children.size() > 1)
	      possibilities(preced, vect);
      else
      {
        //std::cout << "preced =" << preced << std::endl;
	      _fullpreced += ManipStr::toMaj(preced);
        return (search(preced, node, node->children[0]->data));
      }
    }
  else
    {
      _prop.clear();
      fullPossibilities(node);
      return (NULL);
    }
  fullPossibilities(node);            
  return (node);
}

std::string StrDictionary::searching(std::istream& in,
				     std::ostream& out, std::string& str)
{
  CharNode* node;
  std::string input = "";
  std::vector<std::string> tmp;
  size_t i;

  _fullpreced = "";
  node = NULL;
  node = search(str, node, 0);
  if (node)
    dispProp(out) << std::endl;
  while (node != NULL)
  {
    getline(in, input);
    if (input == "ABORT")
      throw MyException("");
      node = search(str, node, input[0]);
    if (_prop.size() > 1)     
      dispProp(out) << std::endl;
    tmp = _propfull;  
    ManipStr::replaceAll(_propfull, ManipStr::toMin(_fullpreced)
      , ManipStr::toMaj(_fullpreced));
    if (_propfull.size() > 1)    
	    dispPropFull(out) << std::endl;
    _propfull = tmp;
  }
  if (_propfull.size() == 0)
    throw MyException("Unknow address");
  if(_propfull.size() == 1)
  {
    str = _propfull[0].c_str();
    return (str);
  }
  //std::cout << "fullpreced = " << _fullpreced << std::endl;

  in >> i;
  if (i < 1 || i > _propfull.size())
    throw MyException("Invalid argument");
  str = _propfull[i - 1];
  return (str);
}
