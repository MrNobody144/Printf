NAME = libftprintf.a
SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)

COMPILE = cc
FLAGS = -Wextra -Werror -Wall -c

LIB = ar rc
RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)
	
$(NAME): $(OBJS)
	$(LIB) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all	
