#include "intersect.h"
using namespace std;


int main(int argc, char* argv[]) {
	Intersect intersect;
	char  file_in[50];
	char  file_out[50];
	ifstream fin;
	for (int i = 1; i < argc; i++) {
		if ((string)argv[i] == "-i") {
			strcpy_s(file_in, argv[i + 1]);
		}
		if ((string)argv[i] == "-o") {
			strcpy_s(file_out, argv[i + 1]);
		}
	}
	intersect.read_from_file(file_in, file_out);
	return 0;
}



