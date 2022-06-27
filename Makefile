##
## EPITECH PROJECT, 2021
## makefile
## File description:
## .
##

SRC	=	src/main.c \
		src/my_cd.c \
		src/my_list.c \
		src/my_command.c \
		src/str_to_word_array.c \
		src/to_cd.c \
		src/check_opmomo.c \
		src/str_word_array.c \
		src/other_command.c \
		src/check_parsing.c \
		src/ft_cat.c \
		src/function_lib.c \
		src/check_opmomo1.c \
		src/tree_creation.c \
		src/tree_traversal.c \

NAME	=	mysh

CC	=	gcc

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include -W -Wextra -Wall -Werror

all:	c_lib $(NAME)

c_lib:
	make -C lib/my/

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) -L./lib/my -lmy

clean:
	$(RM) $(OBJ)
	$(RM) $(CO)

fclean:		clean
	$(RM) $(NAME)
	make fclean -C lib/my/
re:		fclean all
