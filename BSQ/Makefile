NAME = bsq

SRCS = ./srcs/main.c ./srcs/ft_check.c ./srcs/ft_file.c ./srcs/ft_map.c ./srcs/ft_print.c ./srcs/ft_solver.c ./srcs/ft_split.c ./srcs/ft_string.c

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
