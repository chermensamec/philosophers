SRC_LIST_MAN = current_time.c ft_atoi.c init.c lunch.c my_sleep.c philo.c \
	       log.c check_done.c free_error.c

SRC_LIST_BON = init.c  main.c ft_atoi.c free_error.c current_time.c

PATH_MAN = ./philo_man/

PATH_BON = ./philo_bonus/

NAME_MAN = philo

NAME_BON = philo_bonus

INCLUDES_LIST_MAN = philo.h

INCLUDES_LIST_BON = philo_bonus.h

FLAGS = -Wall -Wextra -Werror # -g -fsanitize=thread

SRC_MAN = $(addprefix $(PATH_MAN), $(SRC_LIST_MAN))

SRC_BON = $(addprefix $(PATH_BON), $(SRC_LIST_BON)) 

INCLUDES_MAN = $(addprefix $(PATH_MAN), $(INCLUDES_LIST_MAN))

INCLUDES_BON = $(addprefix $(PATH_BON), $(INCLUDES_LIST_BON))

OBJ_MAN = $(patsubst %.c, %.o, $(SRC_MAN))

OBJ_BON = $(patsubst %.c, %.o, $(SRC_BON))

CC = gcc

all : $(NAME_MAN)

bonus : $(NAME_BON)

$(NAME_MAN) : $(OBJ_MAN) $(INCLUDES_MAN)
	$(CC) $(FLAGS) $(OBJ_MAN) -o $(NAME_MAN) -lpthread  

$(NAME_BON) : $(OBJ_BON) $(INCLUDES_BON)
	$(CC) $(FLAGS) $(OBJ_MAN) -o $(NAME_BON)

%.o : %.c $(INCLUDES_MAN) Makefile
	$(CC) $(FLAGS) -c $< -o $@ -lpthread

clean:
	rm -rf $(OBJ_MAN)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY : all clean fclean re
