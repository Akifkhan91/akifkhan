#include "HeaderFile.h"
double GetDetJacobian(const double nodal_coords[6])
{
	double DetJacobian = ((nodal_coords[2] - nodal_coords[0]) * (nodal_coords[5] - nodal_coords[1])) -
				  		 ((nodal_coords[4] - nodal_coords[0]) * (nodal_coords[3] - nodal_coords[1]));

	return DetJacobian;
}