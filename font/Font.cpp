#include <iostream>
#include <stdio.h>

#include "Font.h"
#include "Frame.h"

using namespace std;

#define W 720
#define H 480
extern unsigned char frame[H][W][3];

void Font::load() {
	const char * cmd = 
		"ffmpeg "
		"-y "
		"-hide_banner "
		"-pattern_type none "
		"-i arial50.png "
		"-f rawvideo "
		"-video_size 384x384 "
		"-pix_fmt rgb24 "
		"-              ";

	FILE * pipe = popen(cmd, "r");
	if (pipe == nullptr) {
		cout << "Error running ffmpeg on arial50.png" << endl;
		exit(1);
	}

	int count = fread((byte *) image, 3, 384 * 384, pipe);
	if (count != 384 * 384) {
		cout << "ERROR.  Unexpected file size of " << count << endl;
		exit(1);
	}

	fflush(pipe);
	pclose(pipe);
}

void Font::draw(int x, int y, string text) {
	for (int y = 0; y < 384; ++y) {
		for (int x = 0; x < 384; ++x) {
			Frame::blendPixel(x, y, .5, image[y][x][0], image[y][x][1], image[y][x][2]);
		}
	}
}

