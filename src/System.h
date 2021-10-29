#ifndef SYSTEM_H
#define SYSTEM_H

#include "Particle.h"
#include "Parameters.h"
#include "Integrator.h"
#include "Interaction.h"
#include "NeighbourList.h"
#include "RNG.h"
//namespace std

//#include <pybind11/pybind11.h>


#include <vector>
#include <cmath>
//#include <memory> // For std::shared_ptr

//namespace py = pybind11;
//using namespace pybind11::literals;



class System {
	
	private:
		Parameters param;
		std::vector<Particle> particles;
		RNG *randini;
		Interaction *inter;
		Integrator *grator;
		NeighbourList *neighbours;
		
		// keep geometry in here for simplicity
		double L;
		
	public:
		// All to be mirrored for the python piece
		System(Parameters _param);
// 		System(py::dict& _parameters);
		//void System();
		// Since I have not figured out how to pass a python dictionary ... in pieces here
		~System();
		
		void InitialiseRandom();
		void step(int _nsteps);
		void step1();
		void output(int _kind);
		
	
};
/*
PYBIND11_MODULE(pyABP, m) {
	py::class_<System>(m, "System")
        //.def(py::init<py::dict &>())
		.def(py::init<>())
        .def("step", &System::step)
        .def("output", &System::output)
}
*/

#endif 
