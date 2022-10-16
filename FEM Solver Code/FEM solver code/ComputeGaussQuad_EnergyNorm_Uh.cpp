#include "HeaderFile.h"
double ComputeGaussQuad_EnergyNorm_Uh(const double nodal_coords[6], const double alpha_nodes[3])
{
	double xi[2];
	double GradN[2], Grad_Uexact[2], Grad_Uh[2] = {0.0, 0.0};
	double ErrorEnergyNorm;
	double IntEval = 0.0;
	double DetJacobian = GetDetJacobian(nodal_coords);
	
	for(int a = 0; a < 3; a++)
	{	
		GetGradFunction(nodal_coords, a, GradN); 
		Grad_Uh[0] += alpha_nodes[a] * GradN[0];
		Grad_Uh[1] += alpha_nodes[a] * GradN[1];
	}

	for(int i = 0; i < SIZE_XIPTS; i++)
	{

		xi[0] = XIPTS[i][0];
		xi[1] = XIPTS[i][1];
		
	
		Compute_Grad_UExact_F2(xi, nodal_coords, Grad_Uexact);
		ErrorEnergyNorm = (Grad_Uexact[0] - Grad_Uh[0]) * (Grad_Uexact[0] - Grad_Uh[0]) +
						  (Grad_Uexact[1] - Grad_Uh[1]) * (Grad_Uexact[1] - Grad_Uh[1]);

		IntEval += QWGTS[i] * ErrorEnergyNorm;
	}
	
	IntEval *= 0.5 * DetJacobian; 
	return IntEval;
}