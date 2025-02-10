CC = cc 
CFLAGS = -Wall -Wextra -Werror

SRC = 	main.c  split.c split_utils.c stack_init.c error.c sort.c three_sort.c \
		move/r.c  move/s_p.c move/rrr.c sort2.c

OBJ = $(SRC:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o:%.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) 
fclean: clean
	rm -rf $(OBJ) $(NAME)

re : fclean all