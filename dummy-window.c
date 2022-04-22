#include "SDL.h"
#include <stdlib.h>

void fill_surface(SDL_Surface *surface) {
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 255, 255));
}

int main(int argc, char **argv) {
	char *title;

	SDL_Window  *window  = NULL;
	SDL_Surface *surface = NULL;

	// Decide on a title
	if (argc >= 2) {
		title = argv[1];
	} else {
		title = "Blank Window";
	}

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Error initializing SDL: %s\n", SDL_GetError());
		return 1;
	}
	atexit(SDL_Quit);

	// Initialize window
	window = SDL_CreateWindow(
		title,
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		128, 128,
		SDL_WINDOW_RESIZABLE
	);

	if (!window) {
		printf("Window creation failed: %s\n", SDL_GetError());
		return 1;
	}

	// Get surface from window
	surface = SDL_GetWindowSurface(window);

	if (!surface) {
		printf("Getting surface failed: %s\n", SDL_GetError());
		return 1;
	}

	fill_surface(surface);
	SDL_UpdateWindowSurface(window);

	// Idle until window closed
	SDL_Event event;
	while (SDL_WaitEvent(&event)) {
		if (event.type == SDL_QUIT) {
			break;
		};

		switch (event.type) {
			case SDL_WINDOWEVENT:
				if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
					surface = SDL_GetWindowSurface(window);
					fill_surface(surface);	
					SDL_UpdateWindowSurface(window);
				}
				break;
		};
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
