NAME = ft_printf.a
GCC = gcc -Wall -Werror -Wextra

OBJECTS = $(COMPULSORY:.c=.o)


all: $(NAME)


$(NAME):
		cd libft; make; cp libft.a ../sources/; cp libft.h ../sources
		cd sources; $(GCC) ft_printf.c main.c

clean:

re:

bonus:

fclean:

re: