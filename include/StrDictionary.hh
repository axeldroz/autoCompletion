//
// StrDictionary.hh for StrDictionary in /home/drozdz_b/rendu/autoCompletion
// 
// Made by drozdz_b
// Login   <drozdz_b@epitech.net>
// 
// Started on  Sun Jul  3 15:56:25 2016 drozdz_b
// Last update Sun Jul  3 15:57:37 2016 drozdz_b
//

#ifndef STRDICTIONARY_HH_
#define STRDICTIONARY_HH_

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <locale>
#include <ostream>
#include <istream>
#include <cstdlib>

#include "CharTree.hh"
#include "ManipStr.hh"
#include "MyException.hh"

class StrDictionary
{
protected: 
    CharTree _tree;

private:
    std::vector<std::string> _prop; 
    std::vector<std::string> _propfull;
    std::vector<std::string> _fullw;
    std::string _fullpreced;
public:
    void fill(const std::list<std::string>& list);
    void fill(const std::list<std::string>& list, bool b);
    void possibilities(const std::string& preced, std::vector<CharNode*>& nodes);
    void fullPossibilities(CharNode* node);
    CharNode* getAskedPos(CharNode* node, std::string& preced, char c);
    std::ostream& dispProp(std::ostream& os);
    std::ostream& dispPropFull(std::ostream& os);
    std::vector<std::string> getPropFull() const;
    CharNode* search(std::string& preced, CharNode* node, char c);
    std::string searching(std::istream& in, std::ostream& out, std::string& str);
};

#endif