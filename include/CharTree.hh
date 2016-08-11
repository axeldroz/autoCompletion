/*
** CharTree.hh for CharTree in /home/drozdz_b/rendu/autocompletion
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Thu Jun 30 09:49:54 2016 drozdz_b
// Last update Tue Jul  5 21:59:46 2016 drozdz_b
*/

#ifndef CHARTREE_HH_
#define CHARTREE_HH_

#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "ManipStr.hh"

struct				CharNode
{
  char				data;
  int				countPrefix;
  int				countWord;
  int				countAll; // pour les doublons
  std::vector<CharNode*>	children;
  std::list<std::string*>	ptrList;
};

class CharTree
{
private:
  CharNode *_root;
  std::list<std::string> _strList;

public:
  CharTree();
  ~CharTree();

  CharNode* getRoot() const;

  CharNode* createNode(char c, bool isEnd, std::string* ptr);
  CharNode* getNode(CharNode *begin, char c);
  CharNode* addLetter(CharNode *begin, char c, bool, std::string*, bool);
  void addWord(const std::string& word, std::string* ptr, bool);
  void addWords(std::string word);
  void addWordList(const std::list<std::string>& list);
  void removeTree(CharNode* node);
  void removeTree();
  void removeTree(CharNode* node, int i);
  void alloc();

  void disp(CharNode* node);
  void disp();
  int getOcc(CharNode *node, char c, int i);
  std::vector<CharNode*> getNextPos(CharNode *node);
  void sortVect(std::vector<CharNode *>& vect, 
  void (CharTree::*fct)(std::vector<CharNode *>& vect));
  void sortVect(std::vector<CharNode *>& vect);
  void sortDescVectByOcc(std::vector<CharNode *>& vect);
  void sortVectByAlphaNum(std::vector<CharNode *>& vect);
  size_t vectByAscii(std::vector<CharNode *>& vect, size_t low, size_t high);
  void swapNode(CharNode *a, CharNode *b);
  void sortByAscii(std::vector<CharNode*>& vect);
};

#endif
