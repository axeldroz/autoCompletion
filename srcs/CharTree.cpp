//
// CharTree.cpp for CharTree in /home/drozdz_b/rendu/autoCompletion
// 
// Made by drozdz_b
// Login   <drozdz_b@epitech.net>
// 
// Started on  Tue Jul  5 23:08:11 2016 drozdz_b
// Last update Tue Jul  5 23:19:39 2016 drozdz_b
//

#include "CharTree.hh"

CharTree::CharTree()
{
  _root = new CharNode;
  _root->data = 0;
  _root->countPrefix = 0;
  _root->countWord = 0;
  _root->ptrList.push_back(NULL);
}

CharTree::~CharTree()
{
  removeTree();
}

void CharTree::alloc()
{ 
  _root = new CharNode;
  _root->data = 0;
  _root->countPrefix = 0;
  _root->countWord = 0;
  _root->countAll = 0;
  _root->ptrList.push_back(NULL);
}

CharNode*     CharTree::getRoot() const
{
  return (_root);
}

CharNode*     CharTree::createNode(char c, bool isEnd, std::string* ptr)
{
  CharNode*    node;

  node = new CharNode;
  node->data = c;
  node->countPrefix = 1;
  node->countWord = (isEnd) ? 1 : 0;
  node->countAll = 1;
  if (ptr != NULL && isEnd)
    node->ptrList.push_back(ptr);
  return (node);
}

CharNode*     CharTree::getNode(CharNode *begin, char c)
{
  std::vector<CharNode*>::iterator it;

  if (begin->data == c)
    return (begin);
  it = begin->children.begin();
  while (it != begin->children.end())
    {
      if ((*it)->data == c)
	return (*it);
      ++it;
    }
  return (NULL);
}

CharNode*     CharTree::addLetter(CharNode *begin, char c, bool isEnd, std::string* ptr, bool doublon)
{
  CharNode    *node;

  node = getNode(begin, c);  
  if (node == NULL)
    {
      node = createNode(c, isEnd, ptr);
      begin->children.push_back(node);
    }
  else
    {
      node->countAll += 1;
      node->countWord += (isEnd) ? 1 : 0;
      node->countPrefix += (!doublon) ? 1 : 0;
      if (isEnd && ptr)
	node->ptrList.push_back(ptr);
    }
  return (node);
}

void    CharTree::addWord(const std::string& word, std::string* ptr, bool doublon)
{
  CharNode*             node;
  bool                  isEnd;
  size_t                   i;

  isEnd = false;
  node = _root;
  i = 0;
  while (i < word.size())
    {
      if ((i + 1) == word.size())
	isEnd = true && !doublon;
      if (word[i] != '\'' && word[i] != '-')
	node = addLetter(node, word[i], isEnd, ptr, doublon);
      ++i;
    }
}

void CharTree::addWords(std::string str)
{
  std::string tmp;
  std::string* ptr;
  size_t start;
  size_t end;
  std::list<std::string>::iterator it;
  bool exists;
  
  str = str.substr(0, str.length() - 1);
  exists = false;
  start = 0;
  end = str.find(' ', start);
  it = _strList.begin();
  while (it != _strList.end())
    {
      if (*it == str)
	exists = true;
      ++it;    
    }
  _strList.push_back(str);
  ptr = &_strList.back();
  do
    {
      end = str.find(' ', start);
      addWord(ManipStr::toMin(str.substr(start, end - start)), ptr, exists);
      start = end + 1;
    }while (end < str.size());
}

void CharTree::addWordList(const std::list<std::string>& list)
{
  std::list<std::string>::const_iterator it;
  
  it = list.begin();
  while (it != list.end())
    {
      addWords(*it);
      ++it;
    }
}

void CharTree::removeTree(CharNode* node)
{
  std::vector<CharNode*>::iterator it;
  
  if (node != NULL)
    {
      it = node->children.begin();
      while (it != node->children.end())
	{
	  removeTree(*it);
	  ++it;
	}
      delete node;
    }
}

void CharTree::removeTree(CharNode* node, int i)
{
  if (node != NULL)
    {
      removeTree(node->children[i], 0);
      removeTree(node, i + 1);
      delete node;
    }
}

void CharTree::removeTree()
{
  if (_root != NULL)
    removeTree(_root);
}

void   CharTree::disp(CharNode* node)
{
  std::vector<CharNode*>::iterator it;

  it = node->children.begin();
  while (it != node->children.end())
    {
      disp(*it);
      ++it;
    }
}

void CharTree::disp()
{
  disp(_root);
}

int CharTree::getOcc(CharNode *node, char c, int i)
{
  std::vector<CharNode*>::iterator it;

  it = node->children.begin();
  i += (node->data == c) ? node->countPrefix : 0;
  while (it != node->children.end())
    {
      i = getOcc(*it, c, i);
      ++it;
    }
  return (i);
}

void CharTree::swapNode(CharNode *a, CharNode *b)
{
  CharNode tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void CharTree::sortDescVectByOcc(std::vector<CharNode *>& vect)
{
  bool is_ok;
  size_t len;
  CharNode* tmp = NULL;
  std::vector<CharNode *>::iterator it;
  
  is_ok = false;
  len = vect.size();
  while (len > 0 && !is_ok)
    {
      is_ok = true;
      it = vect.begin();
      while ((it + 1) != vect.end())
	{
	  if ((*it)->countAll < (*(it + 1))->countAll)
	    {
	      tmp = *it;
	      *it = *(it + 1);
	      *(it + 1) = tmp;
	      is_ok = false;
	    }
	  ++it;
	}
    }
}

void CharTree::sortVectByAlphaNum(std::vector<CharNode *>& vect)
{
  bool is_ok;
  size_t len;
  CharNode* tmp = NULL;
  std::vector<CharNode *>::iterator it;
  
  (void)tmp;
  is_ok = false;
  len = vect.size();
  while (len > 0 && !is_ok)
    {
      is_ok = true;
      it = vect.begin();
      while ((it + 1) != vect.end())
	{
	  if ((*it)->data > (*(it + 1))->data)
	    {
	      tmp = *it;
	      *it = *(it + 1);
	      *(it + 1) = tmp;
	      is_ok = false;
	    }
	  ++it;
	}
    }
}

void CharTree::sortVect(std::vector<CharNode *>& vect)
{
  sortVectByAlphaNum(vect);
  sortDescVectByOcc(vect);   
}

std::vector<CharNode*> CharTree::getNextPos(CharNode *node)
{ 
  std::vector<CharNode*> vect;
  std::vector<CharNode*>::iterator it;
  
  vect = node->children;
  if (node->children.size() > 0)
    sortVect(vect);
  return (vect);
}
