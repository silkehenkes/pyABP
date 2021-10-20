#ifndef INTERACTION_H
#define INTERACTION_H

# include "Particle.h"

class Interaction {
	
private:
	// actual interaction parameters
	double k; // stiffness
	double L; // periodic boundary conditions
	
public:
	Interaction(double k);
	~Interaction();
	double force ( Particle _i, Particle _j, char comp);
	double torque ( Particle _i, Particle _j);
	double wrap(double dx);
};

#endif
