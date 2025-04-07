NAME = philo

INCLUDES = philo.h

SRC =	philo.c\
		utils.c\
		set_up.c\
		clean_up.c\
		errors_utils.c\
		execute.c

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
LIBS = -lpthread
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBS)

norm:
	@norminette *.c *.h

clean:
	@rm -rvf $(OBJ)

fclean: clean
	@rm -rvf $(NAME)

re: fclean all

.PHONY: clean fclean all re test norm
