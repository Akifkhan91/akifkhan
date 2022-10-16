#include<iostream>
#include<cmath>
#include<Eigen/Dense>
#include<Eigen/Sparse>
#include<fstream>
#include<bits/stdc++.h>
#include<cstdlib>
#include<fstream>
#include<vector>
#include<cassert>
#define SIZE_QWGTS 4
#define SIZE_XIPTS 4
using namespace std;
using namespace Eigen;
void ReadMesh(const std::string coord_filename, std::vector<double>& coordinates, const std::string conn_filename, std::vector<int>& connectivity);
double GetElementMeshSize(const double nodal_coords[6]);
double ComputeDistance(const double x1, const double y1, const double x2, const double y2);
bool CheckBoundaryNode(const double node_coordinates[2]);
double GetDetJacobian(const double nodal_coords[6]);
void GetJacobianInv(const double nodal_coords[6], double InvJacobian[][2]);
void GetGradFunction(const double nodal_coords[6], const int a, double GradN[2]);
void ComputeElementMassMatrix(const double nodal_coords[6], const double GradMat[2][3], double LocalMassMat[3][3]);
double GetFunctionVal_F1(const double xi[2], const double nodal_coords[6], const int a);
double Compute_UExact_F1(const double xi[2], const double nodal_coords[6]);
double GetFunctionVal_F2(const double xi[2], const double nodal_coords[6], const int a);
double Compute_UExact_F2(const double xi[2], const double nodal_coordinates[6]);
void Compute_Grad_UExact_F2(const double xi[2], const double nodal_coords[6], double Grad_Uexact[2]);
double ComputeGaussQuad_AprioriError(const double nodal_coords[6], const double alpha_nodes[3]);
double Compute_Uh(const double xi[2], const double alpha_nodes[3]);
double ComputeGaussQuad(const double nodal_coords[6], const int a);
double ComputeGaussQuad_EnergyNorm_Uh(const double nodal_coords[6], const double alpha_nodes[3]);
void Compute_Grad_UExact_F1(const double xi[2], const double nodal_coords[6], double Grad_Uexact[2]);
double ComputeAlphaPiU_F2(double x, double y);
double ComputeGaussQuad_EnergyNorm_PiU(const double nodal_coords[6], const double pi_alpha_nodes[3]);
double ComputeAlphaPiU_F1(double x, double y);
void ComputeGaussQuad_Functional(const double nodal_coords[6], const double alpha_nodes[3], const double pi_alpha_nodes[3], double &Functional_Uh, double &Functional_PiU, double &Functional_Uexact);
double Compute_f_F1(const double xi[2], const double nodal_coords[6]);
double Compute_f_F2(const double xi[2], const double nodal_coords[6]);


const double QWGTS[SIZE_QWGTS] = {-27.0/48.0, 25.0/48.0, 25.0/48.0, 25.0/48.0};

/*
const double QWGTS[SIZE_QWGTS] = {0.223381589678011, 0.223381589678011, 0.223381589678011, 
								  0.109951743655322, 0.109951743655322,0.109951743655322};
*/
const double XIPTS[SIZE_XIPTS][2] = {
									{1.0/3.0, 1.0/3.0}, 
									{0.2, 0.2}, 
									{0.6, 0.2},
									{0.2, 0.6}	
						   			 };

/*
const double XIPTS[SIZE_XIPTS][2] = {
									{0.445948490915965, 0.445948490915965},
									{0.445948490915965, 0.108103018168070},
									{0.108103018168070, 0.445948490915965},
									{0.091576213509771, 0.091576213509771},
									{0.091576213509771, 0.816847572980459},
									{0.816847572980459, 0.091576213509771},
									};
*/