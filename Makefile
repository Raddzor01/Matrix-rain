CC = clang
CFLAGS = -Wall -Wextra -Werror -Wpedantic -lncursesw
FUNCTIONS = src/*.c
FOLDER = obj
A_FILE = minilibmx.a
NAME = matrix_rain
OBJECTS = obj/*.o

all: $(NAME) clean
$(NAME):
	@$(CC) $(CFLAGS) $(FUNCTIONS) -o $@ -I inc
clean:
	rm -rf src/*.h
uninstall: clean
	rm -rf $(NAME)
reinstall: uninstall all
