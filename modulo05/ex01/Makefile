# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/17 10:57:42 by guilmira          #+#    #+#              #
#    Updated: 2022/07/14 12:19:52 by guilmira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= bureaucrat
#--------------------------------------------------------------------------------------------------------------COMPILER
CXX			= clang++
CXXFLAGS	= -Wall -Wextra -Werror
CVERSION	= -std=c++98
CSANITIZE	= -fsanitize=address
#--------------------------------------------------------------------------------------------------------------LIBS
#INCLUDES	= -I ./0includes
#--------------------------------------------------------------------------------------------------------------SOURCES
CLASS		= Bureaucrat.cpp Form.cpp
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
	./$(NAME)

leaks: re
	./$(NAME)

clean:
	@$(REMOVE) $(OBJS)

fclean: clean
	@$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re
#--------------------------------------------------------------------------------------------------------------FORMAT
NONE='\033[0m'
GREEN='\033[1;32m'