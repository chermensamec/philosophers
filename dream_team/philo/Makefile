SRC = current_time.c ft_atoi.c init.c lunch.c my_sleep.c philo.c log.c check_done.c 

NAME = philo

FLAGS = -Wall -Wextra -Werror# -g -fsanitize=thread

OBJ = $(patsubst %.c, %.o, $(SRC))

CC = gcc

INCLUDES = philo.h

all : $(NAME)

$(NAME) : $(OBJ) $(INCLUDES)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) 

%.o : %.c philo.h Makefile
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY : all clean fclean re