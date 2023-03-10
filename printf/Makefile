
NAME = libftprintf.a

SRC = ft_putchar ft_putnbr_base ft_putstr ft_printf

BONUS =

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
AR	= ar rcs

DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

OBJSF		=	.cache_exists

all:		$(NAME)

$(NAME): $(SRC:=.o)
			@$(AR) $(NAME) $(SRC:=.o)
			@echo "$(GREEN)libftprintf compiled"

bonus:	$(BONUS:=.o)
			@$(AR) $(NAME) $(BONUS:=.o)
			@echo "$(GREEN)BONUS compiled"

clean:
			@$(RM)	$(SRC:=.o) $(BONUS:=.o)
			@echo "$(BLUE)Objects are clean"

fclean:		clean
			@$(RM) -f $(NAME)
			@echo "$(CYAN)Everything is clean"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt"

norm:
	@norminette $(SRCS) $(INCLUDES) | grep -v Norme -B1 || true

.PHONY:		all bonus clean fclean re norm