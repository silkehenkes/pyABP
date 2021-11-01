
#include <pybind11/pybind11.h>

#include "System.h"


namespace py = pybind11;
using namespace pybind11::literals;

int notmain() {
	
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
	param.poly = 0.01; // polydispersity of particles (mean 1 hardcoded for now)
	
	// options
	param.saveText = true; // save as text file
	param.saveVTK = true; // save as vtk file
	
	cout << "starting system " << endl;
	
	//System *sys = new System(param);
	System *sys = new System();
	
	cout << "done with system " << endl;
	// equivalent using better pointers
	//std::shared_ptr<System> sys;
	//sys = std::make_shared<System>(param);
	//sys->step1();
// 	sys->step(10,true);
	sys->step(10);
	
	return 0;
}
	

PYBIND11_MODULE(pyABP, m) {
	py::class_<Idiots>(m,"Idiots")
		.def(py::init<>());
		
	py::class_<System>(m, "System")
 		.def(py::init<>());
}

// PYBIND11_MODULE(pyABP, m) {
// // 	py::class_<System>(m, "System")
// // 		.def(py::init<>())
// // 		.def("step", &System::step)
// // 		.def("output", &System::output);
// 	// something idiotic
// 	
// 	py::class_<Idiots>(m,"Idiots")
// 		def(py::init<>());
// 		
// 	//m.def("notmain", &notmain, "calling the main from here");
// }

//.def(py::init<py::dict &>())
