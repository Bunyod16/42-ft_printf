NAME = libftprintf.a
LIBFT = libft.a
GCC = gcc -Wall -Wextra -Werror
CASES =		process_char.c \
						process_str.c \
						process_ptr.c \
						process_dec.c \
						process_u.c \
						utils.c \
						process_x.c \
						utils_itoa_long.c

SOURCES = ft_printf.c

CASES_PATH = $(addprefix cases/, $(CASES))
SOURCES_PATH = $(addprefix sources/, $(SOURCES))

CASES_OBJECTS = $(CASES:.c=.o)
SOURCES_OBJECTS = $(SOURCES:.c=.o)

#Add a default flag to not print directories entered
MAKEFLAGS += --no-print-directory

# OBJECTS = $(CASES:.c=.o) $(SOURCE:.c=.o)
GREEN=\033[32m
END=\033[0m
all: $(NAME)

$(NAME):
		@echo "$(GREEN)Making libft$(END)"
		@cd libft; make re; cp libft.a ../$(NAME); make clean
		@echo "$(GREEN)Creating object files$(END)"
		@$(GCC) -c $(SOURCES_PATH) $(CASES_PATH)
		@echo "$(GREEN)Compiling the library$(END)"
		@ar r $(NAME) $(CASES_OBJECTS) $(SOURCES_OBJECTS)

clean:
	@echo "$(GREEN)Cleaning$(END)"
	@rm -rf $(CASES_OBJECTS) $(SOURCES_OBJECTS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

bonus: $(NAME)

.PHONY: all bonus clean fclean re