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

static void			window_demo(SDL_Window *window)
{
	wait_message(2000);
	printf("\nChange size to 640 * 480\n");
	SDL_SetWindowSize(window, 640, 480);
	wait_message(2000);
	printf("\nHide borders\n");
	SDL_SetWindowBordered(window, SDL_FALSE);
	wait_message(2000);
	printf("\nShow borders\n");
	SDL_SetWindowBordered(window, SDL_TRUE);
	wait_message(2000);
	printf("\nFullscreen\n");
	SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
	wait_message(2000);
}

int					main(int argc, char *argv[])
{
	SDL_Window	*window;

	initialization(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	if (argc == 3)
		window = new_window("Yo", atoi(argv[1]), atoi(argv[2]), 0);
	else
	{
		window = new_window("Yo", 800, 600, 0);
		printf("You can use ./SDL_2_Windows 'width' 'height'\n");
	}
	window_demo(window);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (EXIT_SUCCESS);
}