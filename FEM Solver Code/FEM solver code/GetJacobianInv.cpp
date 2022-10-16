#include "HeaderFile.h"
void GetJacobianInv(const double nodal_coords[6], double InvJacobian[][2])
{
	double DetJacobian = GetDetJacobian(nodal_coords);

	InvJacobian[0][0] = (nodal_coords[5] - nodal_coords[1])/DetJacobian;
	InvJacobian[0][1] = -(nodal_coords[3] - nodal_coords[1])/DetJacobian;
	InvJacobian[1][0] = -(nodal_coords[4] - nodal_coords[0])/DetJacobian;
	InvJacobian[1][1] = (nodal_coords[2] - nodal_coords[0])/DetJacobian;	
}