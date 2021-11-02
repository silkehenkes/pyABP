#ifndef INTERACTION_H
#define INTERACTION_H

# include "Particle.h"

class Interaction {
	
private:
	// actual interaction parameters
	double k; // stiffness
	double L; // periodic boundary conditions
	
public:
	Interaction(double k, double L);
	~Interaction();
	double force (Particle & _i, Particle & _j, int updatewhich);
	double torque (Particle & _i, Particle & _j,int updatewhich) { } // no deterministic torques in ABPs: do nothing
	double wrap(double dx);
};

#endif
