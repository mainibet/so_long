# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 16:31:38 by albetanc          #+#    #+#              #
#    Updated: 2025/05/08 11:44:55 by albetanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_CONFIGURED = $(MLX_DIR)/Makefile.configured # Add a flag to check if MLX was configured

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
$(LIBFT_LIB): $(LIBFT_DIR)/Makefile
	$(MAKE)	-C $(LIBFT_DIR)

# Rule to build MiniLibX
$(MLX_LIB): $(MLX_CONFIGURED)
	$(MAKE) -C $(MLX_DIR) all

# Rule to configure MiniLibX if not already configured
$(MLX_CONFIGURED): ./minilibx-linux/configure
	chmod +x $(MLX_DIR)/configure
	cd $(MLX_DIR) && ./configure
	touch $@

#The obj dir will be created if it doesn't exist
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)
	rm -f $(MLX_CONFIGURED) # Clean the flag file

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	rm -f $(MLX_CONFIGURED)

re: fclean all

.PHONY: all clean fclean re

