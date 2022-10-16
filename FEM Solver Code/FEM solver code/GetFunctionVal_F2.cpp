#include "HeaderFile.h"
double GetFunctionVal_F2(const double xi[2], const double nodal_coords[6], const int a)
{
	double x = ((1 - xi[0] - xi[1]) * nodal_coords[0] + xi[0] * nodal_coords[2] + xi[1] * nodal_coords[4]);
	double y = ((1 - xi[0] - xi[1]) * nodal_coords[1] + xi[0] * nodal_coords[3] + xi[1] * nodal_coords[5]);
	double f_xi = 4 - 2 * x * x - 2 * y * y;

	double DetJacobian = GetDetJacobian(nodal_coords);
	double f;
	switch(a)
	{
		case 0: f = 0.5 * f_xi * (1 - xi[0] - xi[1]) * DetJacobian;
				break;

		case 1: f = 0.5 * f_xi * xi[0] * DetJacobian;
				break;

		case 2: f = 0.5 * f_xi * xi[1] * DetJacobian;
				break;

		default: break;
	}

	return f;
}