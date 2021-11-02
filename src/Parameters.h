#ifndef PARAMETERS_H
#define PARAMETERS_H

// Struct for parametrs of the simulation (collection of properties, not a class)
struct Parameters {
	// geometry and size
	int N; // Number of particles
	double L; // system size
	
	// dynamics
	double dt; // time step
	//int Nsteps; // number of time steps
	//int freq; // saving frequency
	int seed; // RNG seed
	
	// ABPs
	double mu; // mobility
	double Dr; // rotational diffusion constant
	double v0; // self-propulsion velocity
	// Interaction
	double k; // interaction stiffness
	double poly; // polydispersity
	
	// options
	bool verbose; // whether to print debugging output
	//bool saveText; // save as text file
	//bool saveVTK; // save as vtk file
	
};

#endif
