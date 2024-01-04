# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 11:32:38 by lgrimmei          #+#    #+#              #
#    Updated: 2023/11/10 01:17:10 by lgrimmei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors for printing
GREEN = \033[0;32m
RESET = \033[0m

# LIBRARY NAME
NAME			= libft.a

# SOURCE FILES
SRCS			=	ft_isalnum.c ft_isprint.c ft_bzero.c ft_isalpha.c ft_isascii.c\
					ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c\
					ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c\
					ft_strchr.c ft_strrchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c\
					ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c\
					ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
					ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
					*ft_memchr.c ft_strncmp.c ft_memcmp.c\
					ft_lstadd_front.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c\
					ft_lstnew.c ft_lstsize.c ft_lstiter.c ft_lstlast.c ft_lstmap.c\
					ft_printf.c ft_put_char.c ft_put_nbr_hex.c\
					ft_put_nbr.c ft_put_ptr.c ft_put_str.c\
					ft_put_unsigned.c\
					get_next_line.c get_next_line_utils.c

# OBJECTS AND HEADER
OBJS			= $(SRCS:%.c=%.o)
HEADER			= libft.h ft_printf.h get_next_line.h

# COMPILER AND FLAGS
CC				= cc
ARFLAGS 		= rcs
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

# COMPILATION RULES
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# TARGETS
all:			$(NAME)

$(NAME):		$(OBJS) $(HEADER)
				@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
				@echo "$(GREEN)$(NAME) is ready!$(RESET)"

$(OBJDIR):
		mkdir $(OBJDIR)

clean:
				$(RM) $(OBJS) 

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY: all clean fclean re bonus ft_printf get_next_line
