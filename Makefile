##
## EPITECH PROJECT, 2023
## B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
## File description:
## Makefile
##

CC			=	g++

SRC			=	$(wildcard src/*.cpp)	\
				$(wildcard src/**/*.cpp)

TESTS 		=	$(filter-out src/main.cpp , $(SRC))	\
				$(wildcard tests/*.cpp)

OBJ			=	$(SRC:%.cpp=%.o)

NAME		=	nanotekspice

CXXFLAGS	= -std=c++20 -Wall -Wextra -g3 -I./include -I./include/Specials -I./include/Elementary -I./include/Gates -I./include/Advanced

.PHONY: all
all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS)
	make clean

.PHONY: clean
clean:
	rm -f $(OBJ)
	rm -f tests/*.o
	rm -rf *.gc*

.PHONY: fclean
fclean:	clean
	rm -f $(NAME)
	rm -f unit_tests

.PHONY:	re
re:	fclean all

.PHONY: unit_tests
unit_tests:	fclean $(NAME)
	$(CC) -o unit_tests $(TESTS) $(CXXFLAGS) --coverage -lcriterion

.PHONY: tests_run
tests_run:	unit_tests
	./unit_tests

.PHONY: coverage
coverage:	tests_run
	gcovr --exclude tests
