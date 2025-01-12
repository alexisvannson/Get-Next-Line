NAME		= a.out

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

SRCS		= get_next_line.c \
			get_next_line_utils.c

OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
