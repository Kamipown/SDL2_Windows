NAME = SDL2_Windows

FLG = -Wall -Wextra -Werror

SRC = main.c

all: $(NAME)

$(NAME):
	gcc $(FLG) $(SRC) -o $(NAME) -lSDL2

clean:
	rm -f $(NAME)

re: clean all
