##
## Makefile for emacs in /home/Victor/match
## 
## Made by Victor Zhu
## Login   <Victor@epitech.net>
## 
## Started on  Mon Feb 13 21:18:57 2017 Victor Zhu
## Last update Tue Feb 28 13:39:19 2017 Victor Zhu
##

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-I./include -Wall -Wextra

SRCS	=	lib/my_putchar.c	\
		lib/my_put_nbr.c	\
		lib/my_putstr.c		\
		lib/my_putstr_error.c	\
		lib/my_strlen.c		\
		lib/my_atoi.c		\
		src/get_next_line.c	\
		src/check_error.c	\
		src/define_map.c	\
		src/player_turn.c	\
		src/ai_turn.c		\
		src/check_turn.c	\
		src/display.c		\
		src/main.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	matchstick

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	all clean

.PHONY:	all clean fclean re
