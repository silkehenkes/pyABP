# include "Interaction.h"


Interaction::Interaction(double k): k:k L:L { }

// force (repulsive), comp is 0 for x and 1 for y (not using vectors here, inefficient)
double Interaction::force(Particle i, Particle j, char comp) {
	double dx = wrap(j.x - i.x);
	double dy = wrap(j.y - i.y);
	double rij = sqrt(dx*dx + dy*dy);
	double delta = i.R+j.R - rij;
	if (delta>0.0) {
		if (comp == 'x') {
			return - k*delta*dx/rij;
		}
		else if (comp == 'y') {
			return -k*delta*dy/rij;
		}
		else {
			std::cout << "Error: unkwnown component, returning 0!" << endl;
			return 0.0;
		}
	}
	else {
		return 0.0;
	}
}
		
	
double Interaction::torque ( Particle _i, Particle _j) {
	// no deterministic torques in ABPs
	return 0.0;
}

double Interaction::wrap(double dx) {
	if (dx > 0.5*L) {
		return dx-L;
	}
	else if (dx < -0.5*L) {
		return dx + L;
	}
}
