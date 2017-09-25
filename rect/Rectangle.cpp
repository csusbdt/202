#include "Rectangle.h"

Rectangle::Rectangle(SDL_Renderer * renderer, int x, int y, int w, int h) 
: renderer(renderer) {
	rect.x = x; 
	rect.y = y; 
	rect.w = w; 
	rect.h = h; 
}

void Rectangle::update(double dt) {
	rect.x += 100 * dt;
}

void Rectangle::draw() const {
	SDL_RenderFillRect(renderer, &rect);
}

