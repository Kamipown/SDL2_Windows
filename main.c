#include <stdlib.h>
#include <stdio.h>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

static void			initialization(Uint32 flags)
{
	SDL_SetMainReady();
	if (SDL_Init(flags) != 0)
	{
		printf("SDL_Init failed: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

static SDL_Window	*new_window(const char *title, int x, int y, Uint32 flags)
{
	SDL_Window	*window;

	if ((window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, x, y, flags)) == NULL)
	{
		printf("SDL_CreateWindow failed: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	return (window);
}

static void			wait_message(const Uint32 ms)
{
	printf("Wait for %zu ms.\n", ms);
	SDL_Delay(ms);
}

int					main(int argc, char *argv[])
{
	SDL_Window	*window;

	initialization(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	window = new_window("Yo", 800, 600, 0);
	wait_message(5000);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (EXIT_SUCCESS);
}