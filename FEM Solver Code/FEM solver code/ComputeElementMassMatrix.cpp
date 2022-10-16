#include "HeaderFile.h"
void ComputeElementMassMatrix(const double nodal_coords[6], const double GradMat[2][3], double LocalMassMat[3][3])
{
	double DetJacobian = GetDetJacobian(nodal_coords);
	
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			LocalMassMat[i][j] = 0.5 * DetJacobian * (GradMat[0][i] * GradMat[0][j] + GradMat[1][i] * GradMat[1][j]);
}