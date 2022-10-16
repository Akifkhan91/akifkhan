#include "HeaderFile.h"
double Compute_Uh(const double xi[2], const double alpha_nodes[3])
{
	double Uh = 0.0;
	double NHat[3] = {1 - xi[0] - xi[1], xi[0], xi[1]}; 
	for(int i = 0; i < 3; i++)
		Uh += alpha_nodes[i] * NHat[i];

	return Uh;
}