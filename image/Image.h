#pragma once

#include "SDL.h"

class Image {
public:
	Image(SDL_Renderer * renderer, int x, int y);
	void load(const char * filename);
	void update(double dt);
	void draw() const;

private:
	SDL_Renderer * renderer;
	int x;
	int y;
	//SDL_Rect rect;
};

