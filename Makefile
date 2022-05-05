NAME = so_long

SRC =  so_long.c\
	   read_map.c\
	   loop.c\
	   k_o.c\
	   get_next_line_utils.c\
	   get_next_line.c\
	   error_manager.c
	

OBJ = so_long.o\
	  read_map.o\
	  loop.o\
	  k_o.o\
	  get_next_line_utils.o\
	  get_next_line.o\
	  error_manager.o

CFLAGS =  -Wall -Wextra -Werror #-fsanitize=address -g3

CC = gcc -O3

GREEN = \033[1;32m
WHT = \033[1;37m
EOC = \033[1;0m

$(NAME): $(OBJ)
		@date
		@${MAKE} -C mlx 2>.null
		@$(CC) $(CFLAGS) -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ)
		@echo "\n-------CORRECTLY COMPILED------"
	
all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -Imlx -c $^ -o $@	

clean:
	@/bin/rm -rf $(OBJ)
	@/bin/rm -rf .null
	@${MAKE} -C mlx clean
	@echo "---------CLEAN  DONE----------"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "---------FCLEAN  DONE---------"

re: fclean all

.PHONY: all clean fclean re
