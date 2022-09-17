SRCS	=	so_long.c

OBJS	= ${SRCS:.c=.o}

NAME	= so_long

GCC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

MLXFLAGS= -I/usr/include -Iminilibx-linux -O3

%.o:		%.c
		${GCC} ${CFLAGS} ${MLXFLAGS} -c $< -o $@

${NAME}:	mlxlb ${OBJS}
		gcc ${OBJS} -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME}

mlxlb:
		$(MAKE) -C minilibx-linux

all:		${NAME}

clean:
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME} ${NAMEC}
		cd minilibx-linux
		$(MAKE) clean -C minilibx-linux

re:		fclean
		make all

.PHONY:		all clean fclean re bonus
