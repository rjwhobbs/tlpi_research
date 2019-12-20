NAME = libtpli.a

SRC = ./error_functions.c ./get_num.c

OBJ = ./error_functions.o ./get_num.o

all: $(NAME)

$(NAME):
	@gcc -Wall -Werror -Wextra -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -fr $(OBJ)

fclean: clean
	@rm -fr $(NAME)

re: fclean all