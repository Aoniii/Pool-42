NAME = do-op

SRCS = ./srcs/main.c ./srcs/ft_maths.c ./srcs/ft_string.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror -I includes

${NAME}: ${OBJS}
	gcc ${CFLAGS} ${SRCS} -o $@

all: ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: re all clean fclean
