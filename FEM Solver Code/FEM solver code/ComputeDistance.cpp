#include "HeaderFile.h"
double ComputeDistance(const double x1, const double y1, const double x2, const double y2)
{
	double Distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));	
	return Distance;
}