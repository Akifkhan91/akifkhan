#include "HeaderFile.h"
void Compute_Grad_UExact_F1(const double xi[2], const double nodal_coords[6], double Grad_Uexact[2])
{
	double x = ((1 - xi[0] - xi[1]) * nodal_coords[0] + xi[0] * nodal_coords[2] + xi[1] * nodal_coords[4]);
	double y = ((1 - xi[0] - xi[1]) * nodal_coords[1] + xi[0] * nodal_coords[3] + xi[1] * nodal_coords[5]);
	Grad_Uexact[0] = M_PI * cos(M_PI * x) * sin(M_PI * y);
	Grad_Uexact[1] = M_PI * sin(M_PI * x) * cos(M_PI * y); 
}