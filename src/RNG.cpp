#include "RNG.h"

RNG::RNG(int seed): mersenne_twister(seed), uniform_dist(0.0,1.0), normal_dist(0.0,1.0)  { }
	
// normal distribution with mean mu and standard deviation sigma
double RNG::normal(double mu,double sigma) { 
	return (mu + sigma*this->normal());
}
	
// N(0,1) normal distribution
double RNG::normal() { 
	return normal_dist(mersenne_twister);
}
	
// uniform distribution between 0 and 1
double RNG::uniform() {
	return uniform_dist(mersenne_twister);
}
	
