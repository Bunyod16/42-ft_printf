NAME = libftprintf.a
LIBFT = libft.a
GCC = gcc -Wall -Wextra -Werror
CASES = printf_percentage.c \
						printf_char.c \
						printf_char_wdt.c \
						process_char.c \
						printf_char_wdt_dash.c \
						process_str.c \
						printf_str.c \
						process_ptr.c \
						printf_ptr.c \
						process_dec.c \
						printf_dec.c

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

bonus:

.PHONY: all bonus clean fclean re