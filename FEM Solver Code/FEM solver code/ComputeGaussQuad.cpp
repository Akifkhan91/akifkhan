#include "HeaderFile.h"
double ComputeGaussQuad(const double nodal_coords[6], const int a)
{
	double xi[2];
	double f;
	double IntEval = 0.0;

	for(int i = 0; i < SIZE_XIPTS; i++)
	{
		xi[0] = XIPTS[i][0];
		xi[1] = XIPTS[i][1];
		f = GetFunctionVal_F2(xi, nodal_coords, a);
		IntEval += QWGTS[i] * f;
	}

	return IntEval;
}