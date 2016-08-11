//
// MyException.cpp for MyException in /home/drozdz_b/rendu/autoCompletion
// 
// Made by drozdz_b
// Login   <drozdz_b@epitech.net>
// 
// Started on  Mon Jul  4 14:01:31 2016 drozdz_b
// Last update Mon Jul  4 14:05:13 2016 drozdz_b
//

#include "MyException.hh"

MyException::MyException(const char* msg) : std::exception()
{
  _msg = msg;
}

const char* MyException::what() const throw()
{
  return (_msg);
}
