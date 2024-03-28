NAME = philo


SRCS_FILE = main.c process.c utils.c


CC = cc
MD = mkdir -p
CFLAGS = -Wall -Wextra -Werror -g 


DIR_SRC = src/
DIR_OBJ = .object/




OBJS = $(patsubst %.c, ${DIR_OBJ}%.o, ${SRCS})
SRCS = $(addprefix ${DIR_SRC},${SRCS_FILE})
OBJS_BONUS = $(patsubst %.c, ${DIR_OBJ_BONUS}%.o, ${SRCS_BONUS})


RM = rm -Rf

all: ${NAME}

${NAME}: ${OBJS} 
	$(CC) $(OBJS) -o $(NAME) -lpthread


${DIR_OBJ}%.o: %.c ${DIR_SRC}/philo.h Makefile
	mkdir -p $(shell dirname $@)
	$(CC) ${CFLAGS} -c $< -o $@


clean:
	${RM} ${DIR_OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all



.PHONY: all clean fclean re 