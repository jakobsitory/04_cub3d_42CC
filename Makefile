# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by                   #+#    #+#              #
#    Updated: 2024/01/30 12:44:20 by lgrimmei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Colors for printing
GREEN = \033[0;32m
RESET = \033[0m

# NAME
NAME		= cub3D

# SOURCES
SRCS := main.c \
		00_parse/init_window.c \
		00_parse/init_rays.c \
		00_parse/check_map.c \
		00_parse/init_data.c \
		00_parse/parse_colors.c \
		00_parse/parse_file.c \
		00_parse/parse_helpers.c \
		00_parse/parse_map.c \
		00_parse/parse_textures.c \
		00_parse/parse_xpm.c \
		00_parse/read_map.c \
		02_draw/draw_line.c \
		02_draw/draw_map.c \
		02_draw/draw_frame.c \
		02_draw/draw_shader.c \
		02_draw/draw_background.c \
		02_draw/draw_walls.c \
		03_utils/maths.c \
		03_utils/math_helper.c \
		03_utils/vector_cpy.c \
		03_utils/event_hooks.c \
		03_utils/utils.c \
		03_utils/create_move_arrays.c \
		04_free/free_window.c \
		04_free/free_rays.c \
		04_free/free.c \
		01_render/render_walls.c \
		01_render/render_frame.c \
		01_render/render_ray.c \
		01_render/render_player.c \
		01_render/render_background.c
	
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
HEADERS		:= $(addprefix $(INCLDIR)/, cub3D.h libft.h get_next_line.h ft_printf.h)

# FLAGS
CFLAGS		:= -Wall -Wextra -Werror

ifeq ($(MAKECMDGOALS),bonus)
SHADERFLAG := -D SHADER=1
else
SHADERFLAG := -D SHADER=0
endif

#DEBUGFLAGS	:= -g -fsanitize=address
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

bonus: all

# Compile libft.a
$(LIBFT): $(LIBFTDIR)*.c
	@$(MAKE) -C $(LIBFTDIR) all --no-print-directory

$(NAME): $(HEADERS) $(LIBFT) $(OBJDIR) $(OBJS) 
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(OBJS) $(INCS) $(SHADERFLAG) -o $(NAME) $(LIBFTFLAG) $(LIBFTLIB) $(LIBMLXFLAG) $(LIBMLXLIB) $(RLFLAG) -lm
	@echo "$(GREEN)./$(NAME) is ready!$(RESET)"

$(OBJDIR):
	mkdir $(OBJDIR)
	mkdir $(OBJDIR)00_parse
	mkdir $(OBJDIR)01_render
	mkdir $(OBJDIR)02_draw
	mkdir $(OBJDIR)03_utils
	mkdir $(OBJDIR)04_free
		
$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCS) $(SHADERFLAG) -c $< -o $@

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

.PHONY:	all clean fclean re bonus