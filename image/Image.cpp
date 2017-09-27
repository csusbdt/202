#include "Image.h"

Image::Image(SDL_Renderer * renderer, int x, int y) 
: renderer(renderer), x(x), y(y) {
}

void Image::load(const char * filename) {
}

void Image::update(double dt) {
	this->x += 100 * dt;
}

void Image::draw() const {
	//SDL_RenderFillRect(renderer, &rect);
}

