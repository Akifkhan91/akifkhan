#include "HeaderFile.h"
void ComputeGaussQuad_Functional(const double nodal_coords[6], const double alpha_nodes[3], const double pi_alpha_nodes[3], 
	double &Functional_Uh, double &Functional_PiU, double &Functional_Uexact)
{
	double xi[2];
	double Uh, PiU, Grad_Uh_Square, Grad_PiU_Square, Grad_Uh[2] = {0.0, 0.0}, Grad_PiU[2] = {0.0, 0.0}; 
	double Grad_Uexact[2], Grad_Uexact_Square, Uexact;
	
	double GradN[2];
	double f;
	double DetJacobian = GetDetJacobian(nodal_coords);
	double IntEval_Uh = 0.0, IntEval_PiU = 0.0, IntEval_Uexact = 0.0;
	
	for(int a = 0; a < 3; a++)
	{	
		GetGradFunction(nodal_coords, a, GradN); 
		Grad_Uh[0] += alpha_nodes[a] * GradN[0];
		Grad_Uh[1] += alpha_nodes[a] * GradN[1];
		Grad_PiU[0] += pi_alpha_nodes[a] * GradN[0];
		Grad_PiU[1] += pi_alpha_nodes[a] * GradN[1];
	}

	Grad_Uh_Square = Grad_Uh[0] * Grad_Uh[0] + Grad_Uh[1] * Grad_Uh[1];
	Grad_PiU_Square = Grad_PiU[0] * Grad_PiU[0] + Grad_PiU[1] * Grad_PiU[1];

	for(int i = 0; i < SIZE_XIPTS; i++)
	{
		xi[0] = XIPTS[i][0];
		xi[1] = XIPTS[i][1];
		
		Compute_Grad_UExact_F2(xi, nodal_coords, Grad_Uexact);	
		Grad_Uexact_Square = Grad_Uexact[0] * Grad_Uexact[0] + Grad_Uexact[1] * Grad_Uexact[1];
		Uexact = Compute_UExact_F2(xi, nodal_coords);
		
		Uh = Compute_Uh(xi, alpha_nodes);
		PiU = Compute_Uh(xi, pi_alpha_nodes);

		f = Compute_f_F2(xi, nodal_coords);

		IntEval_Uh += QWGTS[i] * (0.5 * Grad_Uh_Square - f * Uh);
		IntEval_PiU += QWGTS[i] * (0.5 * Grad_PiU_Square - f * PiU);
		IntEval_Uexact += QWGTS[i] * (0.5 * Grad_Uexact_Square - f * Uexact);
	}
	
	IntEval_Uh *= 0.5 * DetJacobian;
	IntEval_PiU *= 0.5 * DetJacobian; 
	IntEval_Uexact *= 0.5 * DetJacobian;

	Functional_Uh += IntEval_Uh;
	Functional_PiU += IntEval_PiU;
	Functional_Uexact += IntEval_Uexact;
}
