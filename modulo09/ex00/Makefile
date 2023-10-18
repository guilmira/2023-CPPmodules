# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/17 10:57:42 by guilmira          #+#    #+#              #
#    Updated: 2023/10/05 15:23:27 by guilmira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= btc
ARGS		= btcTest.txt
ARGS2		= CSVdatabase/evaTest.csv
ARGS		= input.txt
#--------------------------------------------------------------------------------------------------------------COMPILER
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror
CVERSION	= -std=c++98
CSANITIZE	= -fsanitize=address
#--------------------------------------------------------------------------------------------------------------LIBS
#INCLUDES	= -I ./0includes
#--------------------------------------------------------------------------------------------------------------SOURCES
CLASS		= BitcoinExchange.cpp
SRCS		= main.cpp $(CLASS)
OBJS		= $(SRCS:.cpp=.o)
#--------------------------------------------------------------------------------------------------------------COMMANDS
REMOVE		= rm -rf
#--------------------------------------------------------------------------------------------------------------RULES
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CVERSION) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(CVERSION) $(OBJS) -o $(NAME)
	@echo $(GREEN) "$(NAME) compiled" $(NONE)

all: $(NAME)

san: $(OBJS)
	$(CXX) $(CXXFLAGS) $(CSANITIZE) $(OBJS) -o $(NAME)
	@echo $(GREEN) "$(NAME) compiled with santitize" $(NONE)

exe: re
	./$(NAME) $(ARGS)

exe2: re
	./$(NAME) $(ARGS2)

leaks: re
	./$(NAME) $(ARGS)

clean:
	@$(REMOVE) $(OBJS)

fclean: clean
	@$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re
#--------------------------------------------------------------------------------------------------------------FORMAT
NONE='\033[0m'
GREEN='\033[1;32m'