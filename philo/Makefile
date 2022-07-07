SRC_MAN = current_time.c ft_atoi.c init.c lunch.c my_sleep.c philo.c \
	       log.c check_done.c free_error.c


NAME = philo

INCLUDES = philo.h

FLAGS = -Wall -Wextra -Werror -pthread -g -fsanitize=thread

OBJ = $(patsubst %.c, %.o, $(SRC_MAN))

CC = gcc

all : $(NAME)

$(NAME) : $(OBJ) $(INCLUDES) Makefile
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)  

%.o : %.c $(INCLUDES) Makefile
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY : all clean fclean re
