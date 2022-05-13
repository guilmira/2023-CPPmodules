# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/17 10:57:42 by guilmira          #+#    #+#              #
#    Updated: 2022/05/13 09:19:19 by guilmira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= tests
#--------------------------------------------------------------------------------------------------------------COMPILER
COMPILER	= clang++
CFLAGS		= -Wall -Wextra -Werror
CVERSION	= -std=c++98
CSANITIZE	= -fsanitize=address
#--------------------------------------------------------------------------------------------------------------LIBS
#INCLUDES	= -I ./0includes
#--------------------------------------------------------------------------------------------------------------SOURCES
CLASS		= Account.cpp
SRCS		= tests.cpp $(CLASS)
OBJS		= $(SRCS:.cpp=.o)
#--------------------------------------------------------------------------------------------------------------COMMANDS
REMOVE		= rm -rf
#--------------------------------------------------------------------------------------------------------------RULES
$(NAME): $(OBJS)
	$(COMPILER) $(CFLAGS) $(CVERSION) $(OBJS) -o $(NAME)
	@echo $(GREEN) "$(NAME) compiled" $(NONE)

all: $(NAME)

san: $(OBJS)
	$(COMPILER) $(CFLAGS) $(CSANITIZE) $(OBJS) -o $(NAME)
	@echo $(GREEN) "$(NAME) compiled with santitize" $(NONE)

exe: san
	./$(NAME)

leaks: re
	./$(NAME)

clean:
	@$(REMOVE) $(OBJS)

fclean: clean
	@$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re norm
#--------------------------------------------------------------------------------------------------------------FORMAT
NONE='\033[0m'
GREEN='\033[1;32m'