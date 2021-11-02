#ifndef SYSTEM_H
#define SYSTEM_H

#include "Particle.h"
#include "Parameters.h"
#include "Integrator.h"
#include "Interaction.h"
#include "NeighbourList.h"
#include "RNG.h"
//namespace std


#include <vector>
#include <cmath>
//#include <memory> // For std::shared_ptr




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
		System();
		//System(Parameters _param);
		//System(py::dict& _parameters);
		//void System();
		// Since I have not figured out how to pass a python dictionary ... in pieces here
		// pybind is sensitive to this not being done right yet!!
		//~System();
		
		void InitialiseRandom();
		void step(int _nsteps, bool debug = true);
		void step1(bool debug);
		void output(int _kind);
		
	
};

class Idiots {
	private:
		bool isidiot;
		
	public:
		
		Idiots();
	//	~Idiots();
};



#endif 
