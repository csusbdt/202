#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

int main(int argc, char * arg[]) {
	FILE * pipe = popen("ls", "r");
	if (pipe == nullptr) {
		cout << "popen failed; " << strerror(errno) << endl;
		return 1;
	}

	fstream fs;
	fs.open("index.html", fstream::out | fstream::trunc);
	if (fs.fail()) {
		cout << "open failed" << endl;
		return 1;
	}

	fs << 
		"<html>\n"
		"  <head>\n"
		"    <title>Index</title>\n"
		"  </head>\n"
		"  <body>\n"
		"    <ul>\n"
	;

	char filename[120];
	while (fscanf(pipe, "%s", filename) != -1) {
		int len = strlen(filename);
		if (len > 4 && strcmp(filename + len - 5, ".html") == 0) {
			fs << "      "
			   << "<li><a href=\""
			   << filename 
			   << "\">"
			   << filename 
			   << "</a></li>" 
			   << endl;
		}
	}

	fs << 
		"    </ul>\n"
		"  </body>\n"
		"</html>\n"
	;

	fs.close();
	fflush(pipe);
	pclose(pipe);
}

