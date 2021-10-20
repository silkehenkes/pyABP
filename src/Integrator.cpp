#include "Integrator.h"


void Integrator(double mu, double v0, double Dr, int seed): mu:mu, v0:v0, Dr:Dr, seed:seed { 
	dynrng = RNG(seed);
	DMAX = 0.0
}

void Integrator::update(Particle p,double dt) {
	// Step 2: ABP update
	for (int i = 0; i < N; i++) {
		double dx = dt*(v0*cos(p.theta) + p.fx);
		double dy = dt*(v0*sin(p.theta) + p.fy);
		p.x += dx;
		p.y += dy;
		p.theta += sqrtdt*2*Dr*dynrng.normal();
		
		// keeping track of maximum move for neighbourlist
		if (fabs(dx)> DMAX) { DMAX = fabs(dx) };
		if (fabs(dy)> DMAX) { DMAX = fabs(dy) };
	}
}
