NAME = so_long

SRCS = so_long.c get_next_line.c get_next_line_utils.c read_map.c error_manager.c loop.c k_o.c
OBJ = so_long.o get_next_line.o get_next_line_utils.o read_map.o error_manager.o loop.o k_o.o

CC = gcc -O3
CFLAGS = -Wall -Wextra -Werror
RM = -rm -r

$(NAME): $(OBJ)
	@${MAKE} -C mlx 2>.null
	@$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "--------CORRECTLY COMPILED--------"

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -Imlx -c $^ -o $@

clean:
	@/bin/rm -rf $(OBJ)
	@/bin/rm -rf .null
	@${MAKE} -C mlx clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "--------CORRECTLY CLEANED--------"

re: fclean all

.PHONY: all fclean clean re
