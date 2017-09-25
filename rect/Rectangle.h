#pragma once

#include "SDL.h"

class Rectangle {
public:
	Rectangle(SDL_Renderer * renderer, int x, int y, int w, int h);
	void update(double dt);
	void draw() const;

private:
	SDL_Renderer * renderer;
	SDL_Rect rect;
};

