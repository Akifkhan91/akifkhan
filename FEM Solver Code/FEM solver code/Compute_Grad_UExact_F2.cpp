#include "HeaderFile.h"
void Compute_Grad_UExact_F2(const double xi[2], const double nodal_coords[6], double Grad_Uexact[2])
{
	double x = ((1 - xi[0] - xi[1]) * nodal_coords[0] + xi[0] * nodal_coords[2] + xi[1] * nodal_coords[4]);
	double y = ((1 - xi[0] - xi[1]) * nodal_coords[1] + xi[0] * nodal_coords[3] + xi[1] * nodal_coords[5]);
	Grad_Uexact[0] = -2 * x * (1 - y * y);
	Grad_Uexact[1] = -2 * y * (1 - x * x); 
}