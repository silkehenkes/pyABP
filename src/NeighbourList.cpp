# include "NeighbourList.h"

NeighbourList::NeighbourList(vector<Particle> particles) {
	// to be implemented
	cout << "Need to implment neighbour list" << endl;
}

NeighbourList::getNeighbours(Particle p) {
	vector<int> neighs;
	// terrible! debug only
	int N = 10;
	for (int k=0; k< N; k++) {
		neighs.push_back(k);
	}
	return neighs
}
