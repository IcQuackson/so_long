
NAME = libft.a

SRC = ft_memset ft_bzero ft_memcpy ft_memmove ft_memchr\
ft_memcmp ft_strlen ft_strchr ft_strrchr ft_atoi ft_strlcpy\
ft_strnstr ft_strncmp ft_isalpha ft_isdigit ft_isalnum\
ft_isascii ft_isprint ft_toupper ft_tolower ft_strlcat\
ft_calloc ft_strdup ft_strjoin ft_strtrim ft_substr\
ft_split ft_itoa ft_strmapi ft_striteri ft_putchar_fd\
ft_putnbr_fd ft_putstr_fd ft_putendl_fd\

BONUS = ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back\
ft_lstdelone ft_lstclear ft_lstiter ft_lstmap\

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

all:		$(NAME) bonus

$(NAME): $(SRC:=.o)
			@$(AR) $(NAME) $(SRC:=.o)
			@echo "$(GREEN)Libft compiled"

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