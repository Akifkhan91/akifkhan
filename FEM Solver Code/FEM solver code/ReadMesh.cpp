#include "HeaderFile.h"

void ReadMesh(const std::string coord_filename,
	      std::vector<double>& coordinates,
	      const std::string conn_filename,
	      std::vector<int>& connectivity)
{
  // Coordinates
  std::fstream pfile;
  pfile.open(coord_filename.c_str(), std::ios::in);
  assert(pfile.good() && "ReadMesh:: Coordinates file does not exist");
  coordinates.clear();
  double val;
  pfile >> val;
  while(pfile.good())
    { coordinates.push_back(val);
      pfile >> val; coordinates.push_back(val);
      pfile >> val; }
  pfile.close();
  assert(coordinates.size()%2==0);
  const int nNodes = static_cast<int>(coordinates.size()/2);

  // Connectivity
  pfile.open(conn_filename.c_str(), std::ios::in);
  assert(pfile.good() && "ReadMesh:: Connectivity file does not exist");
  connectivity.clear();
  int node;
  pfile >> node;
  while(pfile.good())
    { connectivity.push_back(node);
      pfile >> node; connectivity.push_back(node);
      pfile >> node; connectivity.push_back(node);
      pfile >> node; }
  pfile.close();
  assert(connectivity.size()%3==0);
  const int nElements = static_cast<int>(connectivity.size()/3);

  std::cout<<"\nRead "<<nNodes<<" nodes and "<<nElements<<" elements \n"<<std::flush;
  return;
}


