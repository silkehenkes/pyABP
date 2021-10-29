#ifndef OUTPUT_H
#define OUTPUT_H

#include "Parameters.h"
#include "Particle.h"

class Output {
private:
	Output(Parameters _param);
	~Output();
	
public:
	void writeText(vector <Particle> _particles, string* _filename);
	void writeVTP(vector <Particle> _particles, string* _filename);
};

#endif
