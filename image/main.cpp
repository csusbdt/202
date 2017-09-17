#include <iostream>

#include "SDL.h"

int main(int argc, char * argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Window * window = SDL_CreateWindow(
		"CSE 202", 
		SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED, 
		640, 
		480, 
		0);
	if (!window) {
		std::cout << "SDL Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	while (true) {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				SDL_Quit();
				return 0;
			}
		}
	}

	SDL_Quit();

	std::cout << "OK" << std::endl;
}

