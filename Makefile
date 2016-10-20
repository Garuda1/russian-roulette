##
## Makefile
##
## Licensed under GNU GPL v3
## By Thomas Murgia <garuda1@protonmail.com>
##

SOURCE_DIR = ./source
INCLUDE_DIR = ./include
RM = rm -f
NAME = russian-roulette
SRCS = $(SOURCE_DIR)/roulette.c \
			 $(SOURCE_DIR)/randpid.c \
			 $(SOURCE_DIR)/bang.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -ansi -pedantic -O2 -I$(INCLUDE_DIR) -lunixlib

all: $(NAME)

$(NAME): $(OBJS)
			   $(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
				 $(RM) $(OBJS)

fclean: clean
				$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
