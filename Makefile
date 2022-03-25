NAME = so_long

SRCS = so_long.c
OBJ = so_long.o

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = -rm -r

$(NAME): $(OBJ)
	@${MAKE} -C mlx 2>.null
	@$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "AHI VAMOS"

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -Imlx -c $^ -o $@

clean:
	@/bin/rm -rf .null
	@$(RM) *.o

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re
