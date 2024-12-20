SRC = src
INCLUDE = include

PUSH_SWAP = push_swap

DEFAULT = push_swap.c	\
	  pile_parser.c	\
	  move.c	\
	  solver.c

FILES = $(addprefix $(SRC)/, $(DEFAULT))
OBJS = $(FILES:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT_INCLUDE_DIR = $(LIBFT_DIR)
LIBFT = $(LIBFT_DIR)/libft.a

all: $(PUSH_SWAP)

$(PUSH_SWAP): $(OBJS) $(LIBFT)
	cc $(FLAGS) $(OBJS) -o $(PUSH_SWAP) $(LIBFT) -I $(INCLUDE) -I $(LIBFT_INCLUDE_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

%.o: %.c
	cc $(FLAGS) $< -c -o $@ -I $(INCLUDE) -I $(LIBFT_INCLUDE_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(PUSH_SWAP)

debug:
	gcc $(FLAGS) src/*.c libft/*.c -I $(INCLUDE) -I $(LIBFT_INCLUDE_DIR) -o debug -g

re: fclean all

.PHONY: all clean fclean re
