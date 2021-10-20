# include "System.h"

void main(int argc, char* argv[]) {
	
	Parameters param;
	
	param.N = 10; // Number of particles
	param.L = 10.0; // system size
	
	// dynamics
	param.dt = 0.01; // time step
	param.Nsteps = 100; // number of time steps
	param.freq = 1; // saving frequency
	param.seed = 1;
	
	// ABPs
	param.mu = 1.0; // mobility
	param.Dr = 0.1; // rotational diffusion constant
	param.v0 = 0.1; // self-propulsion velocity
	param.k = 1.0; // interaction stiffness
	param.poly = 0.3; // polydispersity of particles (mean 1 hardcoded for now)
	
	// options
	param.saveText = true; // save as text file
	param.saveVTK = true; // save as vtk file
	
	sys = new System(param);
	sys.step1();
}
