##
## Makefile for Makefile in /home/drozdz_b/rendu/autocompletion
## 
## Made by drozdz_b
## Login   <drozdz_b@epitech.net>
## 
## Started on  Thu Jun 30 09:22:15 2016 drozdz_b
## Last update Mon Jul  4 14:06:18 2016 drozdz_b
##

SRC	=	srcs/main.cpp		\
		srcs/AddrDictionary.cpp	\
		srcs/CharTree.cpp	\
		srcs/Parser.cpp		\
		srcs/AutoCompletion.cpp	\
		srcs/ManipStr.cpp	\
		srcs/StrDictionary.cpp	\
		srcs/MyException.cpp

NAME	=	autoCompletion

OBJ	=	$(SRC:.cpp=.o)

RM	=	rm -rf

CC	=	g++

LDFLAGS	=	-Iinclude/ -IKregex

$CFLAGS	+= -g


%.o:		%.cpp
		$(CC) -c -Wall -Werror -Wextra -W -g -o $@ $^ $(LDFLAGS)

$(NAME):	$(OBJ)
		make -C ./Kregex/
		$(CC) -o $(NAME) $(OBJ) -g -L./lib/ -lkregex $(LDFLAGS)

all:	$(NAME)

clean:
	$(RM) $(OBJ)
	make clean -C ./Kregex/

fclean:	clean
	$(RM) $(NAME)
	make fclean -C ./Kregex/

re:	fclean all
