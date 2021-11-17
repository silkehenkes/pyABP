#include "Integrator.h"


Integrator::Integrator(double mu, double v0, double Dr, int seed, double dt): mu(mu), v0(v0), Dr(Dr), dynrng(seed), dt(dt) { 
	Dmax = 0.0;
	sqrtdt = sqrt(dt);
}

void Integrator::update(Particle & p) {
	// Step 2: ABP update
	// set velocities straight here
	p.vx = v0*cos(p.theta) + mu*p.fx;
	p.vy = v0*sin(p.theta) + mu*p.fy;
	// then update positions
	double dx = p.vx*dt;
	double dy = p.vy*dt;
	p.x += dx;
	p.y += dy;
	p.theta += sqrtdt*2*Dr*dynrng.normal();
		
	// keeping track of maximum move for neighbourlist
	if (fabs(dx)> Dmax) { Dmax = fabs(dx); }
	if (fabs(dy)> Dmax) { Dmax = fabs(dy); }
}

void Integrator::resetDmax() {
	 Dmax = 0.0;
}
