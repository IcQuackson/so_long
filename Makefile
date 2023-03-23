# Compiler settings
CC = cc
CFLAGS = -Wall -Wextra -Werror -g# -fsanitize=address

# Directories
SRCDIR = src
OBJDIR = objs
LIBFT_DIR = ./libft
GET_NEXT_DIR = ./get_next_line
CHECKERS_DIR = ./src/map_checkers
HOOKS_DIR = ./src/hooks
FUNC_DIR = ./src/functions

# Source Files
GET_NEXT_SRCS = $(GET_NEXT_DIR)/get_next_line_utils.c $(GET_NEXT_DIR)/get_next_line.c
CHECKERS_SRCS = $(CHECKERS_DIR)/map_checkers1.c $(CHECKERS_DIR)/map_checkers2.c $(CHECKERS_DIR)/map_checkers3.c $(CHECKERS_DIR)/map_checkers4.c
HOOKS_SRCS = $(HOOKS_DIR)/hooks_1.c
FUNC_SRCS = $(FUNC_DIR)/functions.c $(FUNC_DIR)/movement.c

SRCS = $(SRCDIR)/main.c $(CHECKERS_SRCS) $(GET_NEXT_SRCS) $(HOOKS_SRCS) $(FUNC_SRCS)
OBJ = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
LIBFT = $(LIBFT_DIR)/libft.a

# Path to libftprintf.a library
PRINTF_DIR = ./printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Targets
NAME = so_long
ARGS = t.ber

all: 	$(NAME)

bonus:	all

clean:
		cd libft && make clean
		cd printf && make clean
		cd mlx_linux && make clean
		rm -f $(OBJDIR)/*.o

fclean:	clean
		cd libft && make fclean
		cd printf && make fclean
		rm $(NAME)

run:	all
		./so_long $(ARGS)

re:		fclean all

lldb:	all
		lldb -- ./so_long $(ARGS)

gdb:	all
		gdb --args $(NAME) $(ARGS)

valgrind: 	all
			valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./$(NAME) $(ARGS)

libft:
		cd libft && make

minilibx:
		cd mlx_linux && make
printf:
		cd printf && make

$(NAME): $(OBJ)
	cd ./libft && make
	cd ./mlx_linux && make
	cd ./printf && make
	@$(CC) $(OBJ) $(CFLAGS) -Lmlx_linux -lmlx_Linux -L/usr/lib -L$(LIBFT_DIR) -L$(PRINTF_DIR) -Imlx_linux -I$(LIBFT_DIR) -I$(PRINTF_DIR) -lXext -lX11 -lm -lz -lft -lftprintf -o $(NAME)

%.o: %.c
	@$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -I$(LIBFT_DIR) I$(PRINTF_DIR) -O3 -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean bonus main
