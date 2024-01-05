# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 17:18:37 by lgrimmei          #+#    #+#              #
#    Updated: 2024/01/05 12:53:00 by lgrimmei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors for printing
GREEN = \033[0;32m
RESET = \033[0m

# NAME
NAME		= cub3D

# SOURCES
SRCS := main.c\
		utils.c\
		parse_file.c

# DIRECTORIES AND PATHS
INCLDIR		:= include/
INCS		:= -I ./include/ -I/usr/include
SRCDIR		:= src/
OBJDIR		:= obj/
LIBFTDIR	:= libft/
LIBMLXDIR	:= libmlx/
HEADER		:= include/j_cub3d.h

# LIBRARIES
LIBFT		:= $(LIBFTDIR)libft.a
LIBMLX		:= $(LIBMLXDIR)libmlx.a

# COMPILER & COMMANDS
CC			:= cc
RM			:= rm -f

# HEADERS
HEADERS		:= $(addprefix $(INCLDIR)/, cub3d.h libft.h get_next_line.h ft_printf.h)

# FLAGS
CFLAGS		:= -Wall -Wextra -Werror
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
		@$(CC) $(CFLAGS) $(OBJS) $(INCS) -o $(NAME) $(LIBFTFLAG) $(LIBMFTLIB) $(LIBMLXFLAG) $(LIBMLXLIB) $(RLFLAG)
		@echo "$(GREEN)./$(NAME) is ready!$(RESET)"

$(OBJDIR):
		mkdir $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
		$(CC) $(CFLAGS) $(INCS) -c $< -o $@

# Create links of headers in incl folder
$(HEADERS):
		ln -f $(LIBFTDIR)libft.h $(INCLDIR)libft.h
		ln -f $(LIBFTDIR)ft_printf.h $(INCLDIR)ft_printf.h
		ln -f $(LIBFTDIR)get_next_line.h $(INCLDIR)get_next_line.h

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

.PHONY:	all clean fclean re