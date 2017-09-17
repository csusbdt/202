/*
This program generates a playable video file of simple animations 
using the mpeg4 encoding.  It does this by writing raw video frames 
into a running instance of ffmpeg. 
*/

#include <iostream>
#include <sstream>
#include <sys/stat.h>
#include <stdio.h>
#include <cassert>

#include "Font.h"
#include "Frame.h"

typedef unsigned char byte;

using namespace std;

#define W 720
#define H 480

const double frames_per_second = 30;
const int duration_in_seconds = 3;

Font font;

void draw_frame(double t) {
	Frame::clear();
	const double pps = 80; // pixels per second
	Frame::drawRect(0 + t * pps, 0 + t * pps, 20, 10, 0x00, 0xff, 0x00);
	font.draw(100, 100, "Hello");
}

int main(int argc, char * argv[]) {
	font.load();
	Frame::setDimensions(W, H);

	const char * cmd = 
		"ffmpeg              "
		"-y                  "
		"-hide_banner        "
		"-f rawvideo         " // input to be raw video data
		"-pixel_format rgb24 "
		"-video_size 720x480 "
		"-r 60               " // frames per second
		"-i -                " // read data from the standard input stream
		"-pix_fmt yuv420p    " // to render with Quicktime
		"-vcodec mpeg4       "
		"-an                 " // no audio
		"-q:v 5              " // quality level; 1 <= q <= 32
		"output.mp4          ";

	FILE * pipe = popen(cmd, "w");
	if (pipe == 0) {
		cout << "error: " << strerror(errno) << endl;
		return 1;
	}

	int num_frames = duration_in_seconds * frames_per_second;

	for (int i = 0; i < num_frames; ++i) {
		double time_in_seconds = i / frames_per_second;
		draw_frame(time_in_seconds);
		Frame::write(pipe);
	}

	fflush(pipe);
	pclose(pipe);

	cout << "num_frames: " << num_frames << endl;
	cout << "Done." << endl;

	return 0;
}
