#include "HeaderFile.h"
double ComputeAlphaPiU_F2(double x, double y)
{
	double alpha_piU = (1 - x * x) * (1 - y * y);
	return alpha_piU;
}