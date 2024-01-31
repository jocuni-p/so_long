# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 11:48:32 by jocuni-p          #+#    #+#              #
#    Updated: 2024/01/30 17:45:50 by jocuni-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc

CFLAGS = -Wall -Werror -Wextra -g #-fsanitize=address

MLXFLAGS = -framework OpenGL -framework AppKit

NAME = so_long
#-------------------------
NAME_BONUS = so_long_bonus


SRC = main.c map_loader.c map_validator.c handle_error.c free_array_2d.c window_filler.c press_key.c game_finisher.c print_mov.c open_exitdoor.c #print_map.c print_data.c
#------------------------------------------------------------------------------
SRC_BONUS = main_bonus.c map_loader_bonus.c map_validator_bonus.c map_paths_bonus.c handle_error_bonus.c free_array_2d_bonus.c window_filler_bonus.c press_key_bonus.c game_finisher_bonus.c print_mov_bonus.c open_exitdoor_bonus.c tw_animator_bonus.c #print_map.c print_data.c


OBJ_DIR = obj
#------------------------
OBJ_DIR_BONUS = obj_bonus



OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
#--------------------------------------------
OBJ_BONUS = $(addprefix $(OBJ_DIR_BONUS)/, $(SRC_BONUS:.c=.o))


DEPS = $(SRC:.c=.d)
#------------------------
DEPS_BONUS = $(SRC_BONUS:.c=.d)


#=================================REGLAS===============================#


all: makelib makemlx $(OBJ_DIR) $(NAME)

-include $(DEPS)
#---------------------------------------------------
bonus: makelib makemlx $(OBJ_DIR_BONUS) $(NAME_BONUS)

-include $(DEPS_BONUS)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(MLXFLAGS) libft/libft.a mlx/libmlx.a -o $(NAME) $(OBJ)
#--------------------------------------------------------------------------
$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(MLXFLAGS) libft/libft.a mlx/libmlx.a -o $(NAME_BONUS) $(OBJ_BONUS)


$(OBJ_DIR):
	mkdir $(OBJ_DIR)
#--------------------
$(OBJ_DIR_BONUS):
	mkdir $(OBJ_DIR_BONUS)


makelib:
	$(MAKE) -C libft/


makemlx:
	$(MAKE) -C mlx/


$(OBJ_DIR)/%.o : %.c  Makefile so_long.h libft/libft.a mlx/libmlx.a
	$(CC) -c $(CFLAGS) -MMD -MP -MF $(OBJ_DIR)/$*.d $< -o $@
#-------------------------------------------------------------------
$(OBJ_DIR_BONUS)/%.o : %.c  Makefile so_long_bonus.h libft/libft.a mlx/libmlx.a
	$(CC) -c $(CFLAGS) -MMD -MP -MF $(OBJ_DIR_BONUS)/$*.d $< -o $@


clean:
	$(MAKE) -C libft clean
	$(MAKE) -C mlx clean
	rm -f -r $(OBJ_DIR) $(OBJ_DIR_BONUS)


fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME) $(NAME_BONUS)


re: fclean all
#---------------
rebonus: fclean bonus


.PHONY: all makelib makemlx bonus clean fclean re rebonus
