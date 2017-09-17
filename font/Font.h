#pragma once

#include <string>

using namespace std;

typedef unsigned char byte;

class Font {
public:
        void load();
        void draw(int x, int y, string text);

private:
	byte image[384][384][3];
//	byte * image;
};

