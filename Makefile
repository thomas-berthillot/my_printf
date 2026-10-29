CC	=	clang

CFLAGS	= -I.

SRC = $(wildcard my_printf/*.c) \
      $(wildcard my_delta_realloc/*.c) \
	  $(wildcard utils/*.c) \
	  $(wildcard my_printf/puller/*.c)

OBJ = $(SRC:.c=.o)
NAME = libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	mkdir -p ../../include
	cp my.h ../../include/

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)
	rm -f ../../include/my.h

re: fclean $(NAME)

.PHONY: all clean fclean re
