#include "HeaderFile.h"
double Compute_f_F2(const double xi[2], const double nodal_coords[6])
{
	double x = ((1 - xi[0] - xi[1]) * nodal_coords[0] + xi[0] * nodal_coords[2] + xi[1] * nodal_coords[4]);
	double y = ((1 - xi[0] - xi[1]) * nodal_coords[1] + xi[0] * nodal_coords[3] + xi[1] * nodal_coords[5]);
	double f_xi = 4 - 2*x*x - 2*y*y;
	
	return f_xi;
}