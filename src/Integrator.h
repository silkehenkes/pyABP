#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include "RNG.h"
#include "Particle.h"

class Integrator {
	private:
		// random number generator
		//rng normdist;
		RNG dynrng;
		
		// ABP parameters explicitly (taken out of param)
		double mu; //1/zeta, mobility
		double v0;
		double Dr; 
		double dt;
		double sqrtdt;
		
	public:
		Integrator(double _mu, double _v0, double _Dr, int _seed, double dt);
		~Integrator() { }
		
		void update(Particle & p);
		double DMAX; // carrying the current max distance around, for neighbourlist rebuild;
};

#endif
