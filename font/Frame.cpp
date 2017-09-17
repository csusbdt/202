#include <iostream>
#include <sstream>
#include <sys/stat.h>
#include <stdio.h>
#include <cassert>

#include "Frame.h"

typedef unsigned char byte;

using namespace std;

#define W 720
#define H 480

int Frame::width = W;
int Frame::height = H;
byte * Frame::data;

void Frame::setDimensions(int w, int h) {
	assert(w == W);
	assert(h == H);
	width = w;
	height = h;
	delete [] data;
	data = new byte[width * height * 3];
}

void Frame::clear() { 
	memset(data, 0, width * height * 3); 
}

void Frame::write(FILE * output_stream) {
	fwrite(data, 3, width * height, output_stream);
}

// Constrain point to frame.
void Frame::clamp(int * x, int * y) {
	if (*x < 0) *x = 0; else if (*x >= W) *x = W - 1;
	if (*y < 0) *y = 0; else if (*y >= H) *y = H - 1;
}

void Frame::drawRect(int x, int y, int w, int h, byte r, byte g, byte b) {
	int x0 = x;
	int y0 = y;
	clamp(&x0, &y0);
	int x1 = x0 + w;
	int y1 = y0 + h;
	clamp(&x1, &y1);
	for (int y = y0; y < y1; ++y) {
		for (int x = x0; x < x1; ++x) {
			data[(y * width + x) * 3 + 0] = r;
			data[(y * width + x) * 3 + 1] = g;
			data[(y * width + x) * 3 + 2] = b;
		}
	}
}

void Frame::blendPixel(int x, int y, double w, byte r, byte g, byte b) {
	data[(y * width + x) * 3 + 0] *= 1 - w;
	data[(y * width + x) * 3 + 0] += w * r;
	data[(y * width + x) * 3 + 1] *= 1 - w;
	data[(y * width + x) * 3 + 1] += w * g;
	data[(y * width + x) * 3 + 2] *= 1 - w;
	data[(y * width + x) * 3 + 2] += w * b;
}


