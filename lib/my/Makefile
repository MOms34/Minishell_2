##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

CC		=	gcc

CFLAGS		=	-W -Wall -Wextra -Iinclude

LIB_SRC		=	*.c

LIB_OBJ		=	*.o

TARGET_LIB	=	../libmy.a

TARGET_LIBB	=	libmy.a

all:    $(TARGET_LIB)
$(TARGET_LIB):
	$(CC) $(LIB_SRC) -c
	cp my.h ../../include/
	ar src $(TARGET_LIB) $(LIB_OBJ)
	cp ../libmy.a .

clean:
	rm -rf $(LIB_OBJ)

fclean:		clean
	rm -rf $(TARGET_LIBB)
	rm -rf ../../include/my.h
	rm -rf $(TARGET_LIB)

re:	fclean all
