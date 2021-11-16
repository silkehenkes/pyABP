#ifndef SYSTEM_H
#define SYSTEM_H

#include "Particle.h"
#include "Parameters.h"
#include "Integrator.h"
#include "Interaction.h"
#include "NeighbourList.h"
#include "Output.h"
#include "RNG.h"



#include <vector>
#include <cmath>

#include <Python.h>
#include <pybind11/pybind11.h>
namespace py = pybind11;
//using namespace pybind11::literals;


class System {
	
	private:
		Parameters param;
		vector<Particle> particles;
		RNG *randini;
		Interaction *inter;
		Integrator *grator;
		NeighbourList *neighbours;
		Output *writeout;
		
		double cutoff; // Neigbhourlist cutoff (2*(R+poly))
		double maxmove;
		
	public:
		// All to be mirrored for the python piece
		System();
		System(Parameters _param);
		System(py::dict& _parameters);
		Parameters Caster(py::dict& _parameters);
		
		// pybind is sensitive to this not being done right yet!!
		//~System();
		
		void InitialiseRandom();
		void step(int _nsteps);
		void step1();
		void output(string filename1, string filename2, bool _saveText, bool _saveVTP);
		
	
};


#endif 
