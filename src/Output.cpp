#include "Output.h"


Output::Output(Parameters _param) {
	// not thought of anything so far
	cout << "constructed output structure" << endl;
}

// write the data to a new file filename
void Output::writeText(vector <Particle> & particles, string filename) {
	
	// generate and open new file with the correct name
	ofstream outfile(filename);
	// First line is header
	outfile << "index \t  x \t y  \t theta \t  vx \t vy \t omega \t R " << endl;
	for (int i = 0; i< particles.size(); i++) {
		particles[i].printFile(outfile);
	}
	outfile.close();
}
	
	
	
