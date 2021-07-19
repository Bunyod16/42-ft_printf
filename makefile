NAME = ft_printf.a
LIBFT = libft.a
GCC = gcc -Wall -Werror -Wextra
CASES = cases/printf_percentage.c
SOURCES = sources/ft_printf.c

CASES_OBJECTS = $(CASES:.c=.o)
SOURCE_OBJECTS = $(SOURCES:.c=.o)
OBJECTS = $(CASES_OBJECTS) $(SOURCE_OBJECTS)

all: $(NAME)

$(NAME):
		cd libft; make; cp libft.a ../; cp libft.h ../; make fclean
		$(GCC) -c $(SOURCES) $(CASES) $(LIBFT)
		ar rc $(NAME) $(OBJECTS)

clean:

re:

bonus:

fclean:

re: