# include "Interaction.h"

Interaction::Interaction(double k, double L): k(k), L(L) { }

// force (repulsive), comp is 0 for x and 1 for y (not using vectors here, inefficient)
double Interaction::force(Particle i, Particle j, int updatewhich) {
	double dx = wrap(j.x - i.x);
	double dy = wrap(j.y - i.y);
	double rij = sqrt(dx*dx + dy*dy);
	double delta = i.R+j.R - rij;
	double fx = 0.0;
	double fy = 0.0;
	if (delta>0.0) {
		fx = -k*delta*dx/rij;
		fy = -k*delta*dy/rij;
	}
	// update forces in particle here
	// 0 for particle i, 1 for particle j, anything else no update
	if (updatewhich == 0) {
		i.fx += fx;
		i.fy += fy;
	}
	else if (updatewhich == 1) {
		j.fx += -fx;
		j.fy += -fy;
	}
}
		
	
//double Interaction::torque ( Particle _i, Particle _j, int updatewhich) {
//	// no deterministic torques in ABPs
//}

double Interaction::wrap(double dx) {
	if (dx > 0.5*L) {
		return dx-L;
	}
	else if (dx < -0.5*L) {
		return dx + L;
	}
}
