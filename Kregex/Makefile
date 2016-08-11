##
## Makefile for Makefile in /home/drozdz_b/rendu/autocompletion
## 
## Made by drozdz_b
## Login   <drozdz_b@epitech.net>
## 
## Started on  Thu Jun 30 09:22:15 2016 drozdz_b
## Last update Mon Jul  4 09:45:49 2016 Axel Drozdzynski
##

SRC	=	Kregex.cpp

NAME	=	../lib/libkregex.a

OBJ	=	$(SRC:.cpp=.o)

RM	=	rm -rf

CC	=	g++ -Wall -Wextra -Werror -W

%.o:		%.cpp
		g++ -c -Wall -Werror -Wextra -W -o $@ $^

$(NAME):	$(OBJ)
		mkdir -p ../lib
		ar rvs $(NAME) $(OBJ)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
