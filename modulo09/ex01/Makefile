# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/17 10:57:42 by guilmira          #+#    #+#              #
#    Updated: 2023/10/24 14:36:15 by guilmira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= RPN
ARGS		= "2 2 + 4 + 4 +"
ARGS		= "2 2 4 + -"
#ARGS		= "8 9 * 9 - 9 - 9 - 4 - 1 +"
ARGS		= "7 7 * 7 -"


#--------------------------------------------------------------------------------------------------------------COMPILER
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror
CVERSION	= -std=c++98
CSANITIZE	= -fsanitize=address
#--------------------------------------------------------------------------------------------------------------LIBS
#INCLUDES	= -I ./0includes
#--------------------------------------------------------------------------------------------------------------SOURCES
CLASS		= RPN.cpp
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