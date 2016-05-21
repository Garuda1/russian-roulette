##
## Makefile for russian-roulette in /home/admin/Documents/Programming/russian-roulette
## 
## Made by Thomas Murgia
## Login   <garuda1@protonmail.com>
## 
## Started on  Fri May 20 23:11:47 2016 Thomas Murgia
## Last update Sat May 21 11:38:15 2016 Thomas Murgia
##

CC			= gcc
RM			= rm -f
NAME		= russian-roulette
SRCS		= source/roulette.c \
					source/my.c \
					source/randpid.c \
					source/trolls.c
OBJS		= $(SRCS:.c=.o)
CFLAGS	= -Wall -Wextra -Werror -ansi -pedantic -std=c99 -O2 -g3 -I./include

all			: $(NAME)

$(NAME)	: $(OBJS)
					$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean		:
					$(RM) $(OBJS)

fclean	: clean
					$(RM) $(NAME)

re			: fclean all
