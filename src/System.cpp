#include "Particle.h"
#include "System.h"
#include "Parameters.h"

// System constructor for calls through pybind. Uses C++11 constructor delegation
System::System(py::dict& parameters): System(Caster(parameters)){
	// this functions as a test, simultaneously
	if (param.verbose) {
		cout << "Initialised system with parameters from python script!" << endl;
	}
}
	
// transfer parameters out of dictionary into C++ struct (done the pedestrian way here)
Parameters System::Caster(py::dict& parameters) {
	Parameters param;
	param.N = parameters["N"].cast<int>(); // Number of particles
	param.L = parameters["L"].cast<double>(); // system size
	
	// dynamics
	param.dt = parameters["dt"].cast<double>(); // time step
	param.seed = parameters["seed"].cast<int>(); // random seed
	
	// ABPs
	param.mu =  parameters["dt"].cast<double>();  // mobility
	param.Dr =  parameters["Dr"].cast<double>();  // rotational diffusion constant
	param.v0 =  parameters["v0"].cast<double>();  // self-propulsion velocity
	param.k =  parameters["k"].cast<double>();  // interaction stiffness
	param.poly =  parameters["poly"].cast<double>();  // polydispersity of particles (mean 1 hardcoded for now)
	
	// Internal options
	param.verbose = parameters["verbose"].cast<bool>();
	
	return param;
}
	
// System constructor for calls from main within C++
// Gets called by the python version after parameters have been converted to struct form
System::System(Parameters param0): param(param0) {
	// first unwrap the parameters from the dictionary and construct our parameter struct
	
	// NOT doing this using an initalise list
	// also NOT wanting pointers here
	// ergo need default constructors for those guys
	// system class random  number generator
	randini = new RNG(param.seed);
	
	// Create interaction
	cout << "k " << param.k << " L " << param.L <<  endl;
	inter= new Interaction(param.k,param.L);
	cout << "done with interaction " << endl;
	// Create dynamics
	int dynseed = static_cast<int>(param.N*randini->uniform());
	cout << dynseed << endl;
	grator = new Integrator(param.mu, param.v0, param.Dr, dynseed, param.dt);
	cout << "done with integrator " << endl;
	
	// initalise particles: currently random as only option
	InitialiseRandom();
	cout << "done with initialisation " << endl;
	
	// create Neighbourlist
	neighbours = new NeighbourList(particles);
	cout << "done with neighbourlist " << endl;
	
	// create output object
	writeout = new Output(param);
}

// Not good code here and only there as a last resort while debugging
System::System() {
	
	param.N = 10; // Number of particles
	param.L = 10.0; // system size
	
	// dynamics
	param.dt = 0.01; // time step
	param.seed = 1;
	
	// ABPs
	param.mu = 1.0; // mobility
	param.Dr = 0.1; // rotational diffusion constant
	param.v0 = 0.1; // self-propulsion velocity
	param.k = 1.0; // interaction stiffness
	param.poly = 0.01; // polydispersity of particles (mean 1 hardcoded for now)
	
	// options
	param.verbose = true;
	
	// terrible things happen here
	this->~System();
	new (this) System(param);
}
	
	
void System::InitialiseRandom() {
	// actually set up system
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
		if (param.verbose) {
			cout << " Starting step " << k << endl;
		}
		step1();
	}
}

void System::step1 () {
	// local variables
	vector<int> neighs;
	
	// debug: print everybody
	if (param.verbose) {
		cout << "Starting positions, angles, forces and torques" << endl;
		for (int i = 0; i < param.N; i++) {
			particles[i].printDebug();
		}
	}
	// compute interactions
	// Step 1: compute forces 
	for (int i = 0; i < param.N; i++) {
		// compute total force on particle i
		//cout << " Computing forces and torques on particle " << particles[i].index << endl;
		particles[i].fx = 0.0;
		particles[i].fy = 0.0;
		particles[i].torque = 0.0;
		neighs = neighbours->getNeighbours(particles[i]);
 		//for (int j: neighs)
 		//	cout << j << ' ';
		//cout << endl;
		// compute forces and torques
		// get updated from inside inter. '0' means update first particle, '1' would be 2nd particle
		for (int j: neighs) {
			inter->force(particles[i],particles[j],0);
			inter->torque(particles[i],particles[j],0);
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

	
// write to either text or vtk, or both, first filename is text, second is vtp
void System::output(string filename1, string filename2, bool saveText, bool saveVTP) {
	
	// pretty crude
	// else if is important since else we overwrite what we just did
	if (saveText) {
		writeout->writeText(particles,filename1); 
	}
	if (saveVTP) {
		writeout->writeVTP(particles,filename2);
	}
		
}

	
