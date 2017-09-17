#pragma once

//#include <iostream>
//#include <sstream>
//#include <sys/stat.h>
//#include <stdio.h>
//#include <cassert>

typedef unsigned char byte;

using namespace std;

#define W 720
#define H 480

class Frame {
public:
	static void setDimensions(int w, int h);
	static void drawPixel(int x, int y, byte r, byte g, byte b);
	static void blendPixel(int x, int y, double weight, byte r, byte g, byte b);
	static void drawRect(int x, int y, int w, int h, byte r, byte g, byte b);
	static void write();
	static void write(FILE * output_stream);
	static void clear();

private:
	static void clamp(int * x, int * y);

	static int width;
	static int height;
	static byte * data;  //[H][W][3];
};

