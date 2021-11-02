# include "NeighbourList.h"


NeighbourList::NeighbourList(vector<Particle> particles) {
	// to be implemented
	cout << "Need to implement neighbour list properly" << endl;
	// default version ... everybody is everybody's neighbour
	// and that stays fixed throughout the simulation
	vector <int> neighs;
	for (int i = 0; i< particles.size(); i++) { neighs.push_back(particles[i].index); }
	for (int i = 0; i< particles.size(); i++) {
		neighbours.push_back(neighs);
	}
		
}

vector<int> NeighbourList::getNeighbours(Particle p) {
	// general neighbours
	vector<int> neighs = neighbours[p.index];
	// kick self out (no divisions: i is at position i in here
	// remove once the propern neighbour list is constructed
	neighs.erase (neighs.begin() + p.index);
	
	return neighs;
}
