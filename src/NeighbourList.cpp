# include "NeighbourList.h"

/*
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
		
}*/

// vector<int> NeighbourList::getNeighbours(Particle p) {
// 	// general neighbours
// 	vector<int> neighs = neighbours[p.index];
// 	// kick self out (no divisions: i is at position i in here
// 	// remove once the propern neighbour list is constructed
// 	neighs.erase (neighs.begin() + p.index);
// 	
// 	return neighs;
// }



NeighbourList::NeighbourList(vector<Particle> & particles, double cutoff0, double L0):  cutoff(cutoff0), L(L0) {
	
	nbox = static_cast<int>(ceil(L/cutoff));
	cout << "cutoff " << cutoff << " L " << L << " halfnbox " << nbox << endl;
	
	buildList(particles);
}

void NeighbourList::buildList(vector<Particle> & particles) {
	
	// first, do a cell list grid to identify particle location. Grid size cutoff.
	vector <int> xidx;
	vector <int> yidx;
	int temp;
	for (int i = 0; i< particles.size(); i++) {
		// index along x direction, starting at -L/2
		temp = static_cast<int>(floor((L/2+particles[i].x)/cutoff));
		xidx.push_back(temp);
		// and same along y 
		temp = static_cast<int>(floor((L/2+particles[i].y)/cutoff));
		yidx.push_back(temp);
	}	
	// now search through the box and its adjacent ones to set up the neighbour list
	int halfnbox = static_cast<int>(floor(0.5*nbox)); // int to int comparison ...
	for (int i = 0; i< particles.size(); i++) {
		//cout << "working on particle " << i << " indices x " << xidx[i] << " and j " << yidx[i] << endl;
		vector <int> neighs;
		int dxbox;
		int dybox;
		for (int j = 0; j< particles.size(); j++) {
			dxbox = xidx[j]-xidx[i];
			//cout  << "dxbox before: " << dxbox << endl;
			// wrap
			if (dxbox > halfnbox) {dxbox = dxbox-nbox;}
			if (dxbox < -halfnbox) {dxbox = dxbox+nbox;} 
			//cout  << "dxbox after: " << dxbox << endl;
			dybox = yidx[j]-yidx[i];
			//cout  << "dybox before: " << dybox << endl;
			// wrap
			if (dybox> halfnbox) { dybox = dybox-nbox;} 
			if (dybox < -halfnbox) { dybox = dybox+nbox;} 
			//cout  << "dybox after: " << dybox << endl;
			// that is close enough if the index is either -1, 0 or 1
			if ((abs(dxbox)<=1) && (abs(dybox)<=1)) {
				// and not myself!
				if (particles[j].index != particles[i].index) {
					neighs.push_back(particles[j].index);
				}
			}
		}
		neighbours.push_back(neighs);
	}
		
}


void NeighbourList::reBuildList(vector<Particle> & particles) {
	// delete current Neighbourlist and start over
	neighbours.clear();
	buildList(particles);
}
	
vector<int> NeighbourList::getNeighbours(Particle & p) {
	// general neighbours
	vector<int> neighs = neighbours[p.index];
	return neighs;
}


