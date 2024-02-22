NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c utils1.c  utils2.c utils3.c utils5.c split.c s.c sort_3.c utils4.c pa.c pb.c r.c rr.c arguments_handler.c ft_strdup.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	$(CC) $(CFLAGS) ${OBJS} -o ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all
