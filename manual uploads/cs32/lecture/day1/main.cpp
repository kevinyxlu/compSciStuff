/* ZJW simple C++ code to write out an ascii file representing an ellipse */
/* given hardcoded ellipse values size of 32x32 works well */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/* evaluate a 2D point {x, y} against an implicit equation for an ellipse */
/* ellipse defined by {centerX, centerY, radi1, radi2} */
double evalImplicitEllipse(double x, double y, double cenX, double cenY, double rad1, double rad2) {
	double centerX = cenX;
	double centerY = cenY;
	double radi1 = rad1;
	double radi2 = rad2;

	return ( ((centerX-x)*(centerX-x))/(radi1*radi1) + 
				((centerY-y)*(centerY-y))/(radi2*radi2) - 1.0f);
}


/*write out ascii data, using the defined implicit equation 
  interior points write a differnt character then exterior points */
void writeOut(ostream& out, int width, int height, double cenX, double cenY, double rad1, double rad2, char back, char fore) {

	float res;
	for (int y=0; y < height; y++) {
		for (int x =0; x < width; x++) {
			res = evalImplicitEllipse(x, y, cenX, cenY, rad1, rad2);
			if (res < 0)			
				out << back << " ";
			else
				out << fore << " ";
		}
		out << "\n";
	}
}


/*read command line arguments and write out new ascii file of given size */
int main(int argc, char *argv[]) {

	ofstream outFile;
	int sizeX, sizeY;
	double cenX, cenY, rad1, rad2;
	char background, foreground;

	if (argc < 10) {
		cerr << "ERROR, format should be: a.out sizeX sizeY outfileName centerX centerY radius1 radius2 backgroundChar foregroundChar" << endl;
	} else {
		sizeX = stoi(argv[1]);
		sizeY = stoi(argv[2]);
		outFile.open(argv[3]);
		cenX = stoi(argv[4]);
		cenY = stoi(argv[5]);
		rad1 = stoi(argv[6]);
		rad2 = stoi(argv[7]);
		background = *argv[8];
		foreground = *argv[9];
		
		if (outFile) {
			cout << "Writing an image of size: " << sizeX << " " << sizeY << " centered at (" << cenX << ", " << cenY << ") " << "to: " << argv[3] << endl;
			cout << "Foreground char is: " << *(argv[8]) << ", background char is: " << (argv[9]) << endl;
			writeOut(outFile, sizeX, sizeY, cenX, cenY, rad1, rad2, background, foreground);
		} else {
			cout << "Error cannot open outfile" << endl;
			exit(0);
		}
	}

}
