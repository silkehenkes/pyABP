# include "Interaction.h"

Interaction::Interaction(double k0, double L0): k(k0), L(L0) {
	cout << "k " << k << " L " << L <<  endl;
}


// force (repulsive), comp is 0 for x and 1 for y (not using vectors here, inefficient)
double Interaction::force(Particle & i, Particle & j, int updatewhich) {
	//cout << " Particles i " << i.index << " j " << j.index << endl;
	double dx = wrap(j.x - i.x);
	double dy = wrap(j.y - i.y);
	//cout <<" dx " << dx << "  dy " << dy << endl;
	double rij = sqrt(dx*dx + dy*dy);
	double delta = i.R+j.R - rij;
	//cout <<" delta " << delta << endl;
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
	//cout << "fx " << i.fx << ", fy " << i.fy << endl;
}
		
	
//double Interaction::torque ( Particle & _i, Particle & _j, int updatewhich) {
//	// no deterministic torques in ABPs
//}

double Interaction::wrap(double dx) {
	//cout << " dx " << dx << " L " << L << endl;
	if (dx > 0.5*L) {
		return dx-L;
	}
	else if (dx < -0.5*L) {
		return dx + L;
	}
	else {
		return dx;
	}
}
