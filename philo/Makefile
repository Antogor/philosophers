NAME = philo

INCLUDES = philo.h

SRC = philo.c utils.c

CC = gcc
#CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -g $(CFLAGS) -o $(NAME) $(OBJ)

norm:
	@norminette *.c *.h

clean:
	@rm -rvf $(OBJ)

fclean: clean
	@rm -rvf $(NAME)

re: fclean all

.PHONY: clean fclean all re test norm
