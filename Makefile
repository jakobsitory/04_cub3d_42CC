# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschott <jschott@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by                   #+#    #+#              #
#    Updated: 2024/01/23 15:34:20 by jschott          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #




# Colors for printing
GREEN = \033[0;32m
RESET = \033[0m

# NAME
NAME		= cub3D

# SOURCES
SRCS := j_raycaster.c\
		scene_init.c\
		parse_xpm.c\
		window_init.c\
		window_destroy.c\
		draw_background.c\
		draw_walls.c\
		draw_map.c\
		draw_fov.c\
		draw_line.c\
		cast_ray.c\
		render_walls.c\
		input_controls.c\
		maths.c\
		init_data.c\
		utils.c\
		read_map.c\
		parse_map.c\
		free.c\
		parse_file.c\
		parse_helpers.c\
		parse_textures.c\
		parse_colors.c\
		check_map.c\
		main.c
		

# DIRECTORIES AND PATHS
INCLDIR		:= include/
INCS		:= -I include/ -I /usr/include
SRCDIR		:= src/
OBJDIR		:= obj/
LIBFTDIR	:= libft/
LIBMLXDIR	:= libmlx/
HEADER		:= include/cub3d.h

# LIBRARIES
LIBFT		:= $(LIBFTDIR)libft.a
LIBMLX		:= $(LIBMLXDIR)libmlx.a

# COMPILER & COMMANDS
CC			:= cc
RM			:= rm -f

# HEADERS
HEADERS		:= $(addprefix $(INCLDIR)/, j_cub3d.h libft.h get_next_line.h ft_printf.h)

# FLAGS
CFLAGS		:= -Wall -Wextra -Werror
DEBUGFLAGS	:= -g
LIBFTFLAG	:= -L$(LIBFTDIR)
LIBFTLIB	:= -lft
LIBMLXFLAG	:= -L$(LIBMLXDIR)
LIBMLXLIB	:= -lmlx -lXext -lX11

# OBJECTS
OBJ			:= $(SRCS:.c=.o)
OBJS		:= $(addprefix $(OBJDIR), $(OBJ))

# COMPILATION RULES
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# RULES
all: $(NAME) $(LIBFT)

# Compile libft.a
$(LIBFT): $(LIBFTDIR)*.c
	@$(MAKE) -C $(LIBFTDIR) all --no-print-directory

$(NAME): $(HEADERS) $(LIBFT) $(OBJDIR) $(OBJS) 
		@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(OBJS) $(INCS) -o $(NAME) $(LIBFTFLAG) $(LIBFTLIB) $(LIBMLXFLAG) $(LIBMLXLIB) $(RLFLAG) -lm
		@echo "$(GREEN)./$(NAME) is ready!$(RESET)"

$(OBJDIR):
		mkdir $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
		$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCS) -c $< -o $@

# Create links of headers in incl folder
$(HEADERS):
		ln $(LIBFTDIR)libft.h $(INCLDIR)libft.h
		ln $(LIBFTDIR)ft_printf.h $(INCLDIR)ft_printf.h
		ln $(LIBFTDIR)get_next_line.h $(INCLDIR)get_next_line.h

clean:
		$(RM) $(OBJS)
		$(RM) -r $(OBJDIR)
		$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
		$(RM) $(NAME)
		$(MAKE) -C $(LIBFTDIR) fclean
		$(RM) $(INCLDIR)libft.h
		$(RM) $(INCLDIR)ft_printf.h
		$(RM) $(INCLDIR)get_next_line.h

re:		fclean all

val: $(NAME)
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./cub3D

.PHONY:	all clean fclean re