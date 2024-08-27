# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andtan <andtan@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/02 22:39:43 by andtan            #+#    #+#              #
#    Updated: 2024/08/17 02:03:59 by andtan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = ft_printf.c ft_printf_utils.c

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = ft_printf_bonus.c ft_print_char_bonus.c ft_print_integer_bonus.c \
ft_print_unsigned_bonus.c ft_print_hex_bonus.c ft_print_percent_bonus.c \
ft_print_string_bonus.c ft_printf_utils_bonus.c ft_print_pointer_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

bonus: $(LIBFT) $(BONUS_OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(BONUS_OBJS)

$(BONUS_OBJS): %.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

