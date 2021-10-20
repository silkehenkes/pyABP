#ifndef RANDOM_H
#define RANDOM_H
// Random number generator
// Using std C++ engines, not gsl
#include <random>

class RNG {
	
public:
	RNG(int seed);
	~RNG() { }
	
	// normal distribution with mean mu and standard deviation sigma
	double normal(double _mu,double _sigma);
	// N(0,1) normal distribution
	double normal();
	// uniform distribution between 0 and 1
	double uniform();
	
	
private:
	std::mt19937 mersenne_twister; //Mersenne-Twister Random Number generator
	std::uniform_real_distribution<double> uniform_dist; // uniform distribution based on generator
	std::normal_distribution<double> normal_dist; // normal distribution based on generator
};

#endif
