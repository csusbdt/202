#include <iostream>
#include "SDL.h"
#include "Rectangle.h"

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

	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	Rectangle rect(renderer, 100, 100, 200, 50);

	Uint32 previous_millis = SDL_GetTicks();
	while (true) {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				SDL_Quit();
				return 0;
			}
		}
		Uint32 millis = SDL_GetTicks();
		double dt =  (millis - previous_millis) / 1000.0;
		if (dt > 1.0 / 30) {
			SDL_RenderClear(renderer);
			rect.update(dt);
			rect.draw();
			SDL_RenderPresent(renderer);
			previous_millis = millis;
		}
	}

	SDL_Quit();

	std::cout << "OK" << std::endl;
}

