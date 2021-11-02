#ifndef OUTPUT_H
#define OUTPUT_H

#include "Parameters.h"
#include "Particle.h"
#include <vector>
#include <iostream>
#include <fstream>

class Output {
public:
	Output(Parameters _param);
	~Output();
	

	// Syntax: pass particle information by non-modifyable reference 
	// text csv file output
	void writeText(vector <Particle> & _particles, string _filename);
	// vtp output (still empty)
	void writeVTP(vector <Particle> &_particles, string _filename) {}
};

#endif
