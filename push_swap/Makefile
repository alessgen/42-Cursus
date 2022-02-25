# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 12:07:07 by agenoves          #+#    #+#              #
#    Updated: 2022/02/14 12:47:31 by agenoves         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

FILES = ft_array ft_checkarg ft_largearg ft_oldutils ft_oldutils2 \
		ft_oldutils3 ft_operate1 ft_operate2 ft_push_swap \
		ft_sort ft_utils ft_utils2 
		
SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS = ${SRCS:.c=.o}

${NAME}:
	${CC} ${CFLAGS} ${SRCS} -o $@

all: ${NAME} 
${NAME}: ${OBJS}

clean: 
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re