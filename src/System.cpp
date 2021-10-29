#include "Particle.h"
#include "System.h"
#include "Parameters.h"

System::System(Parameters param): param(param) {
// System::System(py::dict& parameters) {
	// first unwrap the parameters from the dictionary and construct our parameter struct
	// to be debugged ...
// 	// geometry and size
// 	param.N = parameters["N"]; // Number of particles
// 	param.L = parameters["L"]; // system size
// 	
// 	// dynamics
// 	param.dt = parameters["dt"]; // time step
// 	param.Nsteps = parameters["Nsteps"]; // number of time steps
// 	param.freq = parameters["freq"]; // saving frequency
// 	param.seed = parameters["seed"];
// 	
// 	// ABPs
// 	param.mu = parameters["mu"]; // mobility
// 	param.Dr = parameters["Dr"]; // rotational diffusion constant
// 	param.v0 = parameters["v0"]; // self-propulsion velocity
// 	param.k = parameters["k"]; // interaction stiffness
// 	param.poly = parameters["poly"]; // polydispersity of particles (mean 1 hardcoded for now)
// 	
// 	// options
// 	param.saveText = parameters["saveText"]; // save as text file
// 	param.saveVTK = parameters["saveVTK"]; // save as vtk file
	
	
	// NOT doing this using an initalise list
	// also NOT wanting pointers here
	// ergo need default constructors for those guys
	
	// Create interaction
	inter= new Interaction(param.k,param.L);
	// Create dynamics
	int dynseed = static_cast<int>(param.N*randini->uniform());
	grator = new Integrator(param.mu, param.v0, param.Dr, dynseed, param.dt);
	
	// initalise particles: currently random as only option
	InitialiseRandom();
	
	// create Neighbourlist
	neighbours = new NeighbourList(particles);
}
	
void System::InitialiseRandom() {
	// actually set up system
	//particles = std::vector<Particle>(0); //init the particle vector 
	// L = param.L; // convenience
	randini = new RNG(param.seed);
	for (int i = 0; i < param.N; i++) {
		// random initial positions and angles
		double x = param.L*(randini->uniform()-0.5); // between -L/2 and L/2
		double y = param.L*(randini->uniform()-0.5); // between -L/2 and L/2
		double theta = 2*M_PI*(randini->uniform()-0.5); // between -pi to pi
		double R = randini->normal(1.0,param.poly); // normally distributed around 1 with width poly
		particles.push_back(Particle(i,x,y,theta,R));
	}	
}

// Multiple stepping: mirrored in pybind
void System::step( int nsteps) {
	for (int k=0; k< nsteps; k++){
		step1();
	}
}

void System::step1 () {
	// local variables
	vector<int> neighs;
	
	// debug: print everybody
	for (int i = 0; i < param.N; i++) {
		particles[i].printDebug();
	}
	// compute interactions
	// Step 1: compute forces 
	for (int i = 0; i < param.N; i++) {
		// compute total force on particle i
		particles[i].fx = 0.0;
		particles[i].fy = 0.0;
		particles[i].torque = 0.0;
		neighs = neighbours->getNeighbours(particles[i]);
		// compute forces and torques
		// get updated from inside inter. '0' means update first particle, '1' would be 2nd particle
		for (int j=0; j < neighs.size(); j++) {
			inter->force(particles[i],particles[j],0);
			inter->torque(particles[i],particles[j],0);
// 			particles[i].fx += fx;
// 			particles[i].fy += fy;
// 			particles[i].torque += torque;
		}
	}
	// loop through particles
	// Euler update
	for (int i = 0; i < param.N; i++) {
		grator->update(particles[i]);
	}
	// periodic boundary conditions
	for (int i = 0; i < param.N; i++) {
		particles[i].wrap(param.L);
	}
	
}

	

void System::output( int kind) {
	
	// pretty crude
	if (kind==0) {
		// output to text file
	}
	else if (kind==1) {
		// output to vtp file
	}
	else {
		std:cout << "Unknown output type, doing nothing!";
	}
}


	
