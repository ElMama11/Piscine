CMD=gcc
FLAGS=-Wall -Werror -Wextra -g

NAME=rush_02

VALGRIND_CMD=valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

SRCPATH=src/
INCLUDE_PATH=include/
OBJPATH=obj/

SRC=main.c \
	function.c

OBJ=$(patsubst %.c,$(OBJPATH)/%.o,$(SRC))

HEADER=./$(SRCPATH)/$(INCLUDE_PATH)

DEP=Makefile ./$(SRCPATH)/$(INCLUDE_PATH)/main.h

all: $(NAME)

$(OBJPATH):
	mkdir -p obj/

$(NAME): $(DEP) $(addprefix $(SRCPATH)/,$(SRC)) $(OBJPATH) $(OBJ)
	$(CMD) $(OBJ) -o $(NAME)

$(OBJPATH)/%.o: $(SRCPATH)/%.c
	$(CMD) $(FLAGS) -c $< -o $@ -I $(HEADER)

clean:
	rm -rf $(OBJPATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all

leaks: $(NAME)
	$(VALGRIND_CMD) ./$(NAME)

.PHONY: all clean fclean re leaks
