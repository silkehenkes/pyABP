#ifndef NEIGHBOURLIST_H
#define NEIGHBOURLIST_H

#include "Particle.h"
#include <vector>

class NeighbourList {

private:
	// doing this one with indices, not pointers
	vector < vector <int>> neighbours;
	double cutoff; // neighbour list cutoff
	double L; // system size
	int nbox;
	
public:
	NeighbourList( vector<Particle> & _particles, double _cutoff, double _L);
	void buildList(vector<Particle> & _particles);
	void reBuildList(vector<Particle> & _particles);
	//~NeighbourList() { }
	
	vector<int> getNeighbours(Particle & _particle);
};

#endif
