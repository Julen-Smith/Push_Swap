# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 21:41:12 by jsmith            #+#    #+#              #
#    Updated: 2022/03/03 13:50:53 by jsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

CC = gcc -fsanitize=address -g3

OBJS = 	push_swap.c	\
		Basic_Functions/Push/push_functions.c \
		Basic_Functions/Reverse_Rotate/reverse_rotate_functions.c \
		Basic_Functions/Rotate/rotate_functions.c \
		Basic_Functions/Swap/swap_functions.c \
		Node/node_management.c\
		Node/node_utils.c\
		Node/specific_node_finder.c \
		Sort/find_coincidences.c \
		Sort/internal_sort.c \
		Sort/middles.c \
		Sort/order_3_case.c \
		Sort/order_10_case.c \
		Sort/order_100_case.c \
		Sort/order_500_case.c \
		Sort/previus_values.c \
		Sort/sort_utils.c \
		Utils/ft_atoi.c \
		Utils/ft_isdigit.c \
		Utils/ft_perror_exit.c \
		Utils/ft_split.c \
		Utils/ft_strlcpy.c \
		Utils/ft_strlen.c \
		Utils/initial_manage.c \

%.o : %.c
	@gcc -c $(OBJS)$(CFLAGS) %< -o $@

all: $(NAME)

$(NAME):
	@$(CC) $(OBJS) $(CFLAGS)  -o push_swap | echo Compiled.
	
clean:
	@rm -f $(NAME) | echo Deleted.

fclean:
	@rm -rf $(NAME) push_swap.dSYM | echo Deleted.

re: fclean all

.PHONY: all clean fclean