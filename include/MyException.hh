//
// MyException.hh for MyException in /home/drozdz_b/rendu/autoCompletion
// 
// Made by drozdz_b
// Login   <drozdz_b@epitech.net>
// 
// Started on  Mon Jul  4 14:01:07 2016 drozdz_b
// Last update Tue Jul  5 22:02:12 2016 drozdz_b
//

#ifndef MYEXCEPTION_HH_
#define MYEXCEPTION_HH_

#include <exception>

class MyException : public std::exception
{
private:
  const char*	_msg;

public:
  MyException(const char* msg);
  const char* what() const throw();
};

#endif
