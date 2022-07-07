SRC_BON = free_error.c init.c log.c my_sleep.c philo_life.c current_time.c \
				ft_atoi.c init_proc.c main.c

NAME_BON = philo_bonus

INCLUDES_BON = philo_bonus.h

FLAGS = -Wall -Wextra -Werror #-g -fsanitize=thread

OBJ_BON = $(patsubst %.c, %.o, $(SRC_BON))

CC = gcc

all : $(NAME_BON)

$(NAME_BON) : $(OBJ_BON) $(INCLUDES_BON) Makefile
	$(CC) $(FLAGS) $(OBJ_BON) -o $(NAME_BON)

%.o : %.c $(INCLUDES_BON) Makefile
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_BON)

fclean: clean
	rm -rf $(NAME_BON)

re:	fclean all

.PHONY : all clean fclean re
