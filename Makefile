SRC = src
INCLUDE = include

PUSH_SWAP = push_swap

DEFAULT = push_swap.c

FILES = $(addprefix $(SRC)/, $(DEFAULT))
OBJS = $(FILES:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(PUSH_SWAP)

$(PUSH_SWAP): $(OBJS) $(LIBFT)
	cc $(FLAGS) $(OBJS) -o $(PUSH_SWAP) -I $(INCLUDE)

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

%.o: %.c
	cc $(FLAGS) $< -c -o $@ -I $(INCLUDE)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(PUSH_SWAP)

re: fclean all

.PHONY: all clean fclean re
