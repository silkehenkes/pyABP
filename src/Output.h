#ifndef OUTPUT_H
#define OUTPUT_H

#include "Parameters.h"
#include "Particle.h"

class Output {
private:
	void Output(Parameters _param);
	void ~Output();
	
public:
	void writeText(vector <Particle> _particles, string* _filename);
	void writeVTP(vector <Particle> _particles, string* _filename);
};

#endif
