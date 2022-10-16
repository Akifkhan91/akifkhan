
#ifndef WRITE_MESH_H
#define WRITE_MESH_H

#include <fstream>
#include <string>
#include <cassert>

void PlotTecFile(const std::string filename,
		 const std::vector<double>& coordinates,
		 const std::vector<int>& connectivity,
		 const double* nodal_field=nullptr)
{
  // Open file to plot
  std::fstream outfile;
  outfile.open(filename.c_str(), std::ios::out);
  
  // Line 1:
  if(nodal_field==nullptr)
    outfile<<"VARIABLES = \"X\", \"Y\" \n";
  else
    outfile<<"VARIABLES = \"X\", \"Y\" \"F1\" \n";
  
  // Line 2:
  const int nNodes = static_cast<int>(coordinates.size()/2);
  const int nElements = static_cast<int>(connectivity.size()/3);
  outfile<<"ZONE t=\"t:0\", N="<<nNodes<<", E="<<nElements<<", F=FEPOINT, ET=TRIANGLE\n";
  
  std::cout.precision(16);
  
  // Nodal coordinates and field values
  for(int i=0; i<nNodes; ++i)
    {
      const double* X = &coordinates[2*i];
      if(nodal_field!=nullptr)
	outfile<<X[0]<<" "<<X[1]<<" "<<nodal_field[i]<<"\n";
      else
	outfile<<X[0]<<" "<<X[1]<<"\n";
    }
  // Connectivity
  for(int e=0; e<nElements; ++e)
    {
      const int* conn = &connectivity[3*e];
      outfile<<conn[0]+1<<" "<<conn[1]+1<<" "<<conn[2]+1<<"\n";
    }
  
  outfile.close();

  // done
  return;
}

#endif
