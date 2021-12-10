NAME = push_swap

SRCS =	push_swap.c utils.c utils2.c array_sort.c sort.c sort_rotate.c big_sort.c\
		ft_big_sort_first.c ft_rrr.c

INCLUDE = push_swap.h

OBJS = $(SRCS:.c=.o)

CC = gcc 

LIBFT  =  -L libft -lft

INC       =  -I libft

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@  

$(NAME) : $(OBJS) $(INCLUDE)
	@make -C ./libft
	$(CC) $(CFLAGS) $(INC) $(LIBFT) $(OBJS) -I./include -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean re all