#include "HeaderFile.h"
double ComputeGaussQuad_AprioriError(const double nodal_coords[6], const double alpha_nodes[3])
{
	double xi[2];
	double Uexact, Uh;
	double Apriori_Error;
	double IntEval = 0.0;
	double DetJacobian = GetDetJacobian(nodal_coords);

	for(int i = 0; i < SIZE_XIPTS; i++)
	{
		xi[0] = XIPTS[i][0];
		xi[1] = XIPTS[i][1];
		Uexact = Compute_UExact_F2(xi, nodal_coords);
		Uh = Compute_Uh(xi, alpha_nodes);
		Apriori_Error = (Uexact - Uh) * (Uexact - Uh);
		IntEval += QWGTS[i] * Apriori_Error;
	}
	IntEval *= 0.5 * DetJacobian; 
	return IntEval;
}