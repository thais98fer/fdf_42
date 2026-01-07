# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/06 17:37:04 by thfernan          #+#    #+#              #
#    Updated: 2026/01/06 19:35:22 by thfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

NAME = fdf
BONUS = fdf_bonus

FDF_HDR = fdf.h
BONUR_HDR = bonus/fdf_bonus.h

FLAGS = -Wall -Wextra -Werror -g3 -I libft -I $(MLX_DIR)
MLX_FLAGS = -lXext -lX11 -lm -lz

LIBFT_A = libft/libft.a
LIBFT_DIR = libft
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

BONUS_DIR = bonus

#=================================================================#
#                            fdf sources                          #
#=================================================================#

SRCS = fdf.c \

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = fdf_bonus.c \
			
BONUS_SRC_PATH = $(addprefix $(BONUS_DIR)/, $(BONUS_SRCS))
BONUS_OBJS = $(BONUS_SRC_PATH:.c=.o)

#=================================================================#
#                               rules                             #
#=================================================================#

# Colors
RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m

all: $(NAME)
	@echo "$(GREEN)	-> Fdf ready $(RESET)"

$(OBJS): $(FDF_HDR)
$(BONUS_OBJS): $(BONUS_HDR)

$(NAME): $(OBJS) $(LIBFT_A) $(MLX_LIB)
	@$(CC) $(OBJS) $(LIBFT_A) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR) all

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS) $(LIBFT_A)
	@$(CC) $(BONUS_OBJS) $(LIBFT_A) -o $(BONUS)
	@echo "$(GREEN)Bonus ready $(RESET)"

%.o: %.c
	@echo "$(YELLOW)Compiling $<$(RESET)"
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@rm -f *.o
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME) $(BONUS)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all bonus clean fclean re
