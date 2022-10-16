#include "HeaderFile.h"
double Compute_UExact_F2(const double xi[2], const double nodal_coords[6])
{
	double x = ((1 - xi[0] - xi[1]) * nodal_coords[0] + xi[0] * nodal_coords[2] + xi[1] * nodal_coords[4]);
	double y = ((1 - xi[0] - xi[1]) * nodal_coords[1] + xi[0] * nodal_coords[3] + xi[1] * nodal_coords[5]);
	double Uexact = (1 - (x * x)) * (1 - (y * y));

	return Uexact;
}