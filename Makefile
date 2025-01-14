GREEN = \033[0;32m
YELLOW = \033[1;33m
ORANGE = \033[38;5;208m
RED = \033[0;31m
CYAN = \033[0;36m
MAGENTA = \033[0;35m
CLEAR = \033[0m

CHECK = [✔ ]
CROSS = [✘]
ARROW = =>
INFO = [i]
SEPARATOR = "${CYAN}=====================================${CLEAR}"


SRC = src
INCLUDE = include


PUSH_SWAP = push_swap
CHECKER = checker
UNIT_TESTS = unit_tests

DEFAULT =	actions/push_ops.c 			\
	 	actions/reverse_rotate_ops.c	 	\
	 	actions/rotate_ops.c 			\
	 	actions/swap_ops.c 			\
		algorithm.c				\
		calculator.c				\
		pile_parser.c				\
		push_swap.c				\
		stack_operations.c			\
		stack_utils.c				\
	 	type.c					\
		utils.c
BONUS =		actions/push_ops.c 			\
	 	actions/reverse_rotate_ops.c	 	\
	 	actions/rotate_ops.c 			\
	 	actions/swap_ops.c 			\
		checker.c				\
		pile_parser.c				\
		stack_utils.c				\
	 	type.c					\
		utils.c

FILES = $(addprefix $(SRC)/, $(DEFAULT))
FILES_BONUS = $(addprefix $(SRC)/, $(BONUS))
FILES_TESTS =	src/actions/push_ops.c			\
		src/actions/reverse_rotate_ops.c	\
		src/actions/rotate_ops.c		\
		src/actions/swap_ops.c			\
		src/pile_parser.c			\
		src/type.c				\
		src/utils.c				\
		tests/actions/push_tests.c		\
		tests/actions/reverse_rotate_tests.c	\
		tests/actions/rotate_tests.c		\
		tests/actions/swap_tests.c		\
		tests/color.c				\
		tests/stack_initializer.c		\
		tests/tester.c				\
		tests/utils.c

OBJS = $(FILES:%.c=%.o)
OBJS_BONUS = $(FILES_BONUS:%.c=%.o)
OBJS_TESTS = $(FILES_TESTS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT_INCLUDE_DIR = $(LIBFT_DIR)
LIBFT = $(LIBFT_DIR)/libft.a

UNIT_TESTS_INCLUDE_DIR = tests

all: $(PUSH_SWAP)

bonus: $(CHECKER)

clean:
	@echo $(SEPARATOR)
	@echo "${RED}${CROSS} Cleaning object files...${CLEAR}"
	make -C $(LIBFT_DIR) clean > /dev/null
	rm -f $(OBJS) $(OBJS_BONUS) $(OBJS_TESTS)
	@echo "${GREEN}${CHECK} All object files cleaned successfully!${CLEAR}"	

fclean: clean
	@echo $(SEPARATOR)
	@echo "${RED}${CROSS} Removing executables...${CLEAR}"
	make -C $(LIBFT_DIR) fclean > /dev/null
	rm -f $(PUSH_SWAP) $(CHECKER) $(UNIT_TESTS)
	@echo "${GREEN}${CHECK} All executables and libraries removed successfully!${CLEAR}"

%.o: %.c
	@echo $(SEPARATOR)
	@echo "${ORANGE}${ARROW} Compiling ${YELLOW}$@${ORANGE}...${CLEAR}"
	cc $(FLAGS) $< -c -o $@ -I $(INCLUDE) -I $(LIBFT_INCLUDE_DIR)

$(PUSH_SWAP): $(OBJS) $(LIBFT)
	@echo $(SEPARATOR)
	@echo "${ORANGE}${ARROW} Compiling ${YELLOW}${PUSH_SWAP}${ORANGE}...${CLEAR}"
	cc $(FLAGS) $(OBJS) -o $(PUSH_SWAP) $(LIBFT) -I $(INCLUDE) -I $(LIBFT_INCLUDE_DIR)
	@echo "${GREEN}${CHECK} ${YELLOW}${PUSH_SWAP}${GREEN} compiled successfully!${CLEAR}"
	@echo $(SEPARATOR)
	@echo "${GREEN}${CHECK} All targets are up to date!${CLEAR}"

$(LIBFT):
	@echo $(SEPARATOR)
	@echo "${MAGENTA}${INFO} Building ${YELLOW}${LIBFT}${MAGENTA}...${CLEAR}"
	make -C $(LIBFT_DIR) bonus > /dev/null
	@echo "${GREEN}${CHECK} ${YELLOW}${LIBFT}${GREEN} built successfully!${CLEAR}"

$(UNIT_TESTS): $(OBJS_TESTS) $(LIBFT)
	@echo "${ORANGE}${ARROW} Compiling ${YELLOW}${UNIT_TESTS}${ORANGE}...${CLEAR}"
	cc $(FLAGS) $(OBJS_TESTS) -o $(UNIT_TESTS) $(LIBFT) -I $(INCLUDE) -I $(LIBFT_INCLUDE_DIR) -I $(UNIT_TESTS_INCLUDE_DIR)
	@echo "${GREEN}${CHECK} ${YELLOW}${UNIT_TESTS}${GREEN} compiled successfully!${CLEAR}"

$(CHECKER): $(OBJS_BONUS) $(LIBFT)
	@echo $(SEPARATOR)
	@echo "${ORANGE}${ARROW} Compiling ${YELLOW}${CHECKER}${ORANGE}...${CLEAR}"
	cc $(FLAGS) $(OBJS_BONUS) -o $(CHECKER) $(LIBFT) -I $(INCLUDE) -I $(LIBFT_INCLUDE_DIR)
	@echo "${GREEN}${CHECK} ${YELLOW}${CHECKER}${GREEN} compiled successfully!${CLEAR}" 

re: fclean all

.PHONY: all clean fclean re bonus
