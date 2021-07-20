NAME = libftprintf.a
LIBFT = libft.a
GCC = gcc -Wall -Werror -Wextra
CASES = printf_percentage.c
SOURCES = ft_printf.c

CASES_OBJECTS = $(CASES:.c=.o)
SOURCES_OBJECTS = $(SOURCES:.c=.o)

CASES_OBJECTS_PATH = $(addprefix cases/, $(CASES_OBJECTS)))
SOURCE_OBJECTS_PATH = $(addprefix sources/, $(SOURCES_OBJECTS)))
OBJECTS = $(CASES_OBJECTS_PATH) $(SOURCE_OBJECTS_PATH)

all: $(NAME)

$(NAME):
		cd libft; make; cp libft.a ../$(NAME); cp libft.h ../; make clean
		$(GCC) -c $(SOURCE_OBJECTS_PATH) $(CASES_OBJECTS_PATH) $(LIBFT)
		ar rc $(NAME) $(OBJECTS)

clean:
	rm -rf $(CASES_OBJECTS) $(SOURCES_OBJECTS) $(LIBFT) $(LIBFT:.a=.h)

re:

bonus:

fclean:

re: