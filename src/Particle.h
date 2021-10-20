
#ifndef PARTICLE_H
#define PARTICLE_H

// Particle is a class containing the 3 degrees of freedom x y and angle
class Particle {
	
	private:
		int index;
		double x; // x position
		double y; // y position
		double theta; // angle
		double R; // radius
		double fx; // total x force
		double fy; // total y force
		double torque; // total torque
	
	public:
		Particle(int _index, double _x, double _y, double _theta, double _R);
		//Particle(Particle _particle); // copy constructor - do I need to do this manually?
		~Particle();
		void printDebug();
		void wrap(double L);
};

#endif
