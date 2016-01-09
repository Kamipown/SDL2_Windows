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

static void			wait_message(const Uint32 ms)
{
	printf("Wait for %zu ms.\n", ms);
	SDL_Delay(ms);
}

int					main(int argc, char *argv[])
{
	initialization(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	wait_message(5000);
	SDL_Quit();
	return (EXIT_SUCCESS);
}