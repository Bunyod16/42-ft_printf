NAME = libftprintf.a
LIBFT = libft.a
GCC = gcc -Wall -Werror -Wextra
CASES = printf_percentage.c \
						printf_char.c \
						printf_char_wdt.c \
						process_char.c \
						printf_char_wdt_dash.c
SOURCES = ft_printf.c

CASES_PATH = $(addprefix cases/, $(CASES))
SOURCES_PATH = $(addprefix sources/, $(SOURCES))

CASES_OBJECTS = $(CASES:.c=.o)
SOURCES_OBJECTS = $(SOURCES:.c=.o)

# OBJECTS = $(CASES:.c=.o) $(SOURCE:.c=.o)

all: $(NAME)

$(NAME):
		cd libft; make re; cp libft.a ../$(NAME); make clean
		$(GCC) -c $(SOURCES_PATH) $(CASES_PATH)
		ar r $(NAME) $(CASES_OBJECTS) $(SOURCES_OBJECTS)

clean:
	rm -rf $(CASES_OBJECTS) $(SOURCES_OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

bonus:

.PHONY: all bonus clean fclean re