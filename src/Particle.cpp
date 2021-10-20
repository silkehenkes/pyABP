#include "Particle.h"

// Particle constructor: give it positions, angle, radius. Piece HERE is a shortcut to pass those variables immediately
Particle::Particle(int index, double x, double y, double theta, double R): index:index, x:x, y:y, theta:theta, R:R {
	fx = 0.0; // total x force
	fy = 0.0; // total y force
	torque = 0.0; // total torque
}

// periodic boundary conditions in x, y and theta [ turn off for MSDs, e.g.]
Particle::wrap(double L) {
	if (x > 0.5*L) { 
		x = x-L;
	}
	if (x < -0.5*L) { 
		x = x+L;
	}
	if (y > 0.5*L) { 
		y = y-L;
	}
	if (y < -0.5*L) { 
		y = y+L;
	}
	if (theta > M_PI) { 
		theta = theta - 2*M_PI;
	}
	if (theta < -M_PI) { 
		theta = theta + 2*M_PI;
	}
}

Particle::printDebug() {
	std::cout << "Particle " << index << ", x " << x ", y " << y << ", theta " << theta << ", R " << R << ", fx " << fx << ", fy " << fy << ", torque " << torque << endl;
}
