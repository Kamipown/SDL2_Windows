#include <stdlib.h>
#include <stdio.h>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

static void	initialization(Uint32 flags)
{
	SDL_SetMainReady();
	if (SDL_Init(flags) != 0)
	{
		printf("SDL_Init failed: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

int			main(int argc, char *argv[])
{
	initialization(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	// Code \\
	SDL_Quit();
	return (EXIT_SUCCESS);
}