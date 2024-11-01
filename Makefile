# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzary <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 17:48:57 by mzary             #+#    #+#              #
#    Updated: 2024/11/01 04:24:38 by mzary            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

NAME = libft.a
MSRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
	ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
	ft_strlen.c ft_strmapi.c ft_striteri.c ft_strncmp.c \
	ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
	ft_tolower.c ft_toupper.c
BSRC = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c \
	ft_lstnew_bonus.c ft_lstsize_bonus.c
MOBJ = $(MSRC:.c=.o)
BOBJ = $(BSRC:.c=.o)
MHDR = libft.h
BHDR = libft_bonus.h

all: $(NAME)

$(NAME): $(MOBJ)

bonus: $(MOBJ) $(BOBJ)

%bonus.o: %bonus.c $(BHDR)
	$(CC) $(CFLAGS) -c $< -o $@
	$(AR) $(NAME) $@

%.o: %.c $(MHDR)
	$(CC) $(CFLAGS) -c $< -o $@
	$(AR) $(NAME) $@

clean:
	$(RM) $(MOBJ) $(BOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean
