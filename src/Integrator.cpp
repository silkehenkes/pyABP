#include "Integrator.h"


Integrator::Integrator(double mu, double v0, double Dr, int seed, double dt): mu(mu), v0(v0), Dr(Dr), dynrng(seed), dt(dt) { 
	DMAX = 0.0;
	sqrtdt = sqrt(dt);
}

void Integrator::update(Particle p) {
	// Step 2: ABP update
	double dx = dt*(v0*cos(p.theta) + p.fx);
	double dy = dt*(v0*sin(p.theta) + p.fy);
	p.x += dx;
	p.y += dy;
	p.theta += sqrtdt*2*Dr*dynrng.normal();
		
	// keeping track of maximum move for neighbourlist
	if (fabs(dx)> DMAX) { DMAX = fabs(dx); }
	if (fabs(dy)> DMAX) { DMAX = fabs(dy); }
}
