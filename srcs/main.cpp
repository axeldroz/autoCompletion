/*
** main.cpp for main in /home/drozdz_b/rendu/autocompletion
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Thu Jun 30 09:23:11 2016 drozdz_b
// Last update Tue Jul  5 23:12:19 2016 drozdz_b
*/

#include <iostream>
#include <string>

#include "AutoCompletion.hh"
#include "MyException.hh"
#include "CharTree.hh"

int	main(int ac, char **av)
{
  AutoCompletion prog;
  std::string param;
  
  if (ac < 2)
    {
      std::cout << "Invalid argument" << std::endl;
      return (84);
    }
  param = av[1];
  if (param == "-h")
    std::cout << "USAGE" << std::endl
              << "     " << av[0] << " dictionnary"
              << std::endl << std::endl
              << "DESCRIPTION" << std::endl
              << "     "
              << "dictionnary file, containing" 
              << " one address per line, serving as knowledge base"
              << std::endl;
  else
    {
      try
	{
	  prog.getAddresses(param);
	  prog.goCity(std::cin, std::cout);
	}
      catch (MyException e)
	{
	  if (e.what()[0] != '\0')
	    std::cout << e.what() << std::endl;
	  else 
	    return (0);
	  return (84);
	}
  //     catch (std::exception e)
	// {
	//     std::cout << e.what() << std::endl;
      
	//   return (84);
	// }
    }
  return (0);
}
