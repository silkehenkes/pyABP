
#ifndef PARTICLE_H
#define PARTICLE_H

#include <cmath>
// debug printing
#include <iostream>
// real printing
#include <fstream>
using namespace std;

// Particle is a class containing the 3 degrees of freedom x y and angle
// this is scarcely more than a struct, make all members public
class Particle {
	
	public:
		int index;
		double x; // x position
		double y; // y position
		double theta; // angle
		double R; // radius
		double fx; // total x force
		double fy; // total y force
		double torque; // total torque
		// not dynamical variable, but safekeeping
		double vx;
		double vy;
	
		Particle(int _index, double _x, double _y, double _theta, double _R);
		~Particle() { } // nothing fancy in there
		void printDebug();
		void printFile(ofstream & _outfile);
		void wrap(double L);
};

#endif
