#include "HeaderFile.h"
void GetGradFunction(const double nodal_coords[6], const int a, double GradN[2])
{
	double InvJacobian[2][2];
	double GradNa[2];
	switch(a)
	{
		case 0: GradNa[0] = -1.0;
				GradNa[1] = -1.0;
				break;

		case 1: GradNa[0] = 1.0;
				GradNa[1] = 0.0;
				break;

		case 2: GradNa[0] = 0.0;
				GradNa[1] = 1.0;
				break;

		default: break;
	}
	GetJacobianInv(nodal_coords, InvJacobian);
	GradN[0] = InvJacobian[0][0] * GradNa[0] + InvJacobian[0][1] * GradNa[1];
	GradN[1] = InvJacobian[1][0] * GradNa[0] + InvJacobian[1][1] * GradNa[1]; 
}
