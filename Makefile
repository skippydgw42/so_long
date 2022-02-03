NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror ##-Imlx


FLAGSX = -Lmlx -lmlx -framework OpenGL -framework AppKit

HEADER = ./includes/so_long.h		\

GNL =	./gnl/get_next_line.c		\

ADD =	./add/ft_free.c				\
		./add/ft_modlen.c			\

INIT = 	./init/setup_tiles.c		\
		./init/put_imgs.c			\
		./init/map_init.c			\
		./init/game_init.c			\
		./init/player_init.c		\

PARSING =	./parsing/map_check.c	\
			./parsing/check_err.c	\

PARAMS =	./params/close.c		\
			./params/move.c			\
			./params/keynput.c		\
			./params/player_moves.c	\

SRCS =	./srcs/main.c				\
		${GNL}						\
		${PARSING}					\
		${PARAMS}					\
		${ADD}						\
		${INIT}						\

OBJS = ${SRCS:.c=.o}

LIB = ./mlx/libmlx.a ./libft/libft.a

all : library ${NAME}

library :
	make -C ./mlx
	make -C ./libft

%.o : %.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${OBJS} ${LIB}
	${CC} ${FLAGSX} ${OBJS} ${LIB} -o ${NAME}

clean :
	make -C ./mlx clean
	make -C ./libft clean
	/bin/rm -f ${OBJS}

fclean : clean
	/bin/rm -f mlx/libmlx.a
	/bin/rm -f libft/libft.a
	/bin/rm -f ${NAME}

re : fclean	all

.PHONY : all library mlx clean fclean re  
