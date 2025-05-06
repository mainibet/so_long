# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 16:31:38 by albetanc          #+#    #+#              #
#    Updated: 2025/05/06 13:30:57 by albetanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
MLX_DIR = ./minilibx-linux #linux
MLX_LIB = $(MLX_DIR)/libmlx.a

NAME = so_long
SRC = main.c window.c map.c map_check.c map_utils.c findpath.c graphic.c render.c move.c
OBJ_DIR = ./obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# MiniLibX flags for Linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz


all: $(NAME)

# Link object files and libft to create the executable and the graphic library
$(NAME): $(OBJ) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) $(MLX_FLAGS) -o $@

# Rule to build libft if it doesn't exist
$(LIBFT_LIB): 
	$(MAKE)	-C $(LIBFT_DIR)

#Rule to build MiniLibx if doesn't exist
 $(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

#The obj dir will be created if it doesn't exist
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJ_DIR)/*.o

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	rm -f $(MLX_CONFIGURED)

re: fclean all

.PHONY: all clean fclean re

