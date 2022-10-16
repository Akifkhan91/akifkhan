#include "HeaderFile.h"
double GetElementMeshSize(const double nodal_coords[6])
{
	double LengthEdge[3];
	LengthEdge[0] = ComputeDistance(nodal_coords[0], nodal_coords[1], nodal_coords[2], nodal_coords[3]);
	LengthEdge[1] = ComputeDistance(nodal_coords[0], nodal_coords[1], nodal_coords[4], nodal_coords[5]);
	LengthEdge[2] = ComputeDistance(nodal_coords[2], nodal_coords[3], nodal_coords[4], nodal_coords[5]);
	int n = sizeof(LengthEdge) / sizeof(double);

	return (*max_element(LengthEdge, LengthEdge + n));
}