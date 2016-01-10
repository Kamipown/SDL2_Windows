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

/*
	Functions used :

	SDL_Window* SDL_CreateWindow(const char* title, int x, int y, int w, int h, Uint32 flags)
	void SDL_Delay(Uint32 ms)
	void SDL_SetWindowSize(SDL_Window* window, int w, int h)
	void SDL_SetWindowBordered(SDL_Window* window, SDL_bool bordered)
	int SDL_SetWindowFullscreen(SDL_Window* window, Uint32 flags)

	SDL_CreateWindow returns an SDL_Window on success or NULL on failure.
		Use SDL_WINDOWPOS_CENTERED to center the window.
		The SDL_Window is implicitly shown if SDL_WINDOW_HIDDEN is not set.

	SDL_Delay waits a specified number of milliseconds before returning.

	SDL_SetWindowSize change the size of a window.

	SDL_SetWindowBordered show or hide window's borders.

	SDL_SetWindowFullscreen change a window state to fullscreen or windowed.
		The flag SDL_WINDOW_FULLSCREEN will change the videomode.
		The flag SDL_WINDOW_FULLSCREEN_DESKTOP just takes the size of the desktop.
		Use 0 for windowed mode.
		This function returns 0 on success or a negative error code on failure.

	Notes:
	- Use SDL_GetWindowFlags to get the currents flags of a window.
	- Use SDL_GetWindowSize to get the size of a window.
*/