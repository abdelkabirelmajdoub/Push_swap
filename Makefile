CC = cc 
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
NAMEB = checker

SRC = 	main.c  split.c split_utils.c stack_init.c error.c sort.c three_sort.c \
		move/r.c  move/s_p.c move/rrr.c sort2.c

SRCB = 	SRCB/main_bonus.c SRCB/split_bonus.c SRCB/utils_bonus.c \
		SRCB/gnl_bonus.c SRCB/gnl_utils_bonus.c\
		SRCB/stack_init_bonus.c SRCB/error_bonus.c \
		SRCB/move/r.c  SRCB/move/s_p.c SRCB/move/rrr.c 

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(NAMEB): $(OBJB) 
	$(CC) $(CFLAGS) $(OBJB) -o $(NAMEB)

%.o:%.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(OBJB)
fclean: clean
	rm -rf $(NAME) $(NAMEB)

re : fclean all

bonus: $(NAMEB)