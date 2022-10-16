#include "HeaderFile.h"
bool CheckBoundaryNode(const double node_coordinates[2])
{
	if((abs(node_coordinates[0] + 1) < 1e-8) || (abs(node_coordinates[0] - 1) < 1e-8) || 
	   (abs(node_coordinates[1] + 1) < 1e-8) || (abs(node_coordinates[1] - 1) < 1e-8))
		return true;
	else
		return false;
}