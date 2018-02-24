##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=	srcs/brain.c			\
		srcs/connecting/connections.c	\
		srcs/connecting/first_connection.c	\
		srcs/game/is_win.c		\
		srcs/game/replace_maps.c	\
		srcs/game/replace_enemy_map.c	\
		srcs/game/orders.c		\
		srcs/game/turns.c		\
		srcs/map/create_map.c		\
		srcs/map/ships_position.c	\
		srcs/map/init_maps.c		\
		srcs/map/converter.c		\
		srcs/print/print_maps.c		\
		srcs/sig/recup_sig.c		\
		srcs/sig/count_sig.c		\
		srcs/sig/send_attack_sig.c	\
		srcs/error_gest/attack_err.c	\
		srcs/error_gest/ships_error_handling.c	\
		srcs/get_next_line.c		\

OBJ	=	$(SRC:.c = .o)

NAME	=	navy

LIB_DIR	=	./lib

MY.H_DIR	=	./include

CC	=	gcc -g3

C_FLAGS	=	-Wall -Wextra

LIB_FLAG	=	-L$(LIB_DIR) -lmy

INCL_FLAG	=	-I$(MY.H_DIR)

all:	$(NAME)

$(NAME):	$(OBJ)
		$(MAKE) -C lib/my
		$(CC) -o $(NAME) $(OBJ) $(C_FLAGS) $(LIB_FLAG) $(INCL_FLAG)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean all re clean
