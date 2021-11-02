#ifndef NEIGHBOURLIST_H
#define NEIGJBOURLIST_H

#include "Particle.h"
#include <vector>

class NeighbourList {

private:
	// doing this one with indices, not pointers
	vector < vector <int>> neighbours;
	
public:
	NeighbourList( vector<Particle> _particles);
	//~NeighbourList() { }
	
	vector<int> getNeighbours(Particle _particle);
};

#endif
