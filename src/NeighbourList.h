#ifndef NEIGHBOURLIST_H
#define NEIGJBOURLIST_H

#include "Particle.h"

class NeighbourList {

private:
	// doing this one with indices, not pointers
	std::vector < std::vector <int>> neighbours;
	
public:
	NeighbourList( std::vector<Particle> _particles);
	~NeighbourList();
	
	std::vector<int> getNeighbours(Particle _particle);
};

#endif
