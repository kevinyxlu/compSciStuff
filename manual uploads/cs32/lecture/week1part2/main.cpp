/* ZJW simple C++ code to write out an ascii file representing an ellipse */
/* given hardcoded ellipse values size of 32x32 works well */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/* simple data representation of an implicit ellipse */
class ellipse {
  public:
	ellipse(double cX, double cY, double r1, double r2, char C) : 
		centerX(cX), centerY(cY), radi1(r1), radi2(r2), inC(C) {}

	double eval(double x, double y) {
		return ( ((centerX-x)*(centerX-x))/(radi1*radi1) + 
				((centerY-y)*(centerY-y))/(radi2*radi2) - 1.0f);
	}
	char getInC() const {return inC; }

  private:
	double centerX, centerY; //center point of ellipse
	double radi1, radi2; //radii of the ellipse
	char inC; //what character to draw for interior of ellipse
};


/*write out ascii data, using the defined implicit equation 
  interior points write a differnt character then exterior points */
void writeOut(ostream& out, int width, int height, char outC, vector<ellipse *> IEs) {

	float res;
	char lastInC = 'z';
	bool inTrue = false;

	//for every point in the 2D space
	for (int y=0; y < height; y++) {
		for (int x =0; x < width; x++) {
			//reset variables
			lastInC = 'z';
			inTrue = false;
			//iterate through all possible equations (note 'front' determined by order in vector)
			for (ellipse* eq : IEs) {
				res = eq->eval(x, y);

				if (res < 0) {
					lastInC = eq->getInC();
					inTrue = true;
				}
			}
			if (inTrue) {			
				out << lastInC << " ";
			}
			else
				out << outC << " ";
		}
		out << "\n";
	}
}


/*read command line arguments and write out new ascii file of given size */
int main(int argc, char *argv[]) {

	ofstream outFile;
	int sizeX, sizeY;
	// create all the equations for a simple asci face
	// note order in vector matters
	vector<ellipse *> theEquations;
	theEquations.push_back(new ellipse(16, 16, 11, 13,'O'));
	theEquations.push_back(new ellipse(8, 8, 3, 2,'-'));
	theEquations.push_back(new ellipse(24, 8, 3, 2,'-'));
	theEquations.push_back(new ellipse(16, 24, 5, 6,'-'));

	if (argc < 4) {
		cerr << "Error format: a.out sizeX sizeY outfileName" << endl;
	} else {
		sizeX = stoi(argv[1]);
		sizeY = stoi(argv[2]);
		outFile.open(argv[3]);
		if (outFile) {
			cout << "writing an image of size: " << sizeX << " " << sizeY << " to: " << argv[3] << endl;
			writeOut(outFile, sizeX, sizeY, '|', theEquations);
		} else {
			cout << "Error cannot open outfile" << endl;
			exit(0);
		}
	}

}
