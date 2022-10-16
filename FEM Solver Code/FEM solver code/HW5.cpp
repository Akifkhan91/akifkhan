#include "HeaderFile.h"

int main(void)
{
	// Part A
	vector<double> coordinates;
	vector<int> connectivity;
	typedef Triplet<double> T;

	ReadMesh("meshes/meshes/coordinates-6.dat",coordinates,
		"meshes/meshes/connectivity-6.dat", connectivity);	

	int nNodes = coordinates.size()/2;
	int nElements = connectivity.size()/3;
	double ElementMeshSize[nElements];
	double ElementForceVec[3];
	double LocalMassMat[3][3];
	double GradMat[2][3], GradN[2];
	
	SparseMatrix<double, Eigen::RowMajor> GlobalMassMat(nNodes, nNodes);
	VectorXd GlobalForceVec(nNodes);
	GlobalForceVec = VectorXd::Zero(nNodes);
	VectorXd Soln(nNodes);
	std::vector<T> tripletList;

	for(int i = 0; i < connectivity.size(); i += 3)
	{
		int node_0 = connectivity.at(i);
		int node_1 = connectivity.at(i+1);
		int node_2 = connectivity.at(i+2);

		double nodal_coords[6] = {
									coordinates.at(2*node_0), coordinates.at(2*node_0+1),
									coordinates.at(2*node_1), coordinates.at(2*node_1+1),
									coordinates.at(2*node_2), coordinates.at(2*node_2+1)
					   			 };  


		for(int a = 0; a < 3; a++)
		{	
			GetGradFunction(nodal_coords, a, GradN);
			GradMat[0][a] = GradN[0];
			GradMat[1][a] = GradN[1]; 

//			Element Force Vector is 0 if f = 0, which we have
//			Already initialized to 0

			ElementForceVec[a] = ComputeGaussQuad(nodal_coords, a);
		}
		
		ComputeElementMassMatrix(nodal_coords, GradMat, LocalMassMat);
		tripletList.push_back({node_0, node_0, LocalMassMat[0][0]});
		tripletList.push_back({node_0, node_1, LocalMassMat[0][1]});
		tripletList.push_back({node_0, node_2, LocalMassMat[0][2]});
		tripletList.push_back({node_1, node_0, LocalMassMat[1][0]});
		tripletList.push_back({node_1, node_1, LocalMassMat[1][1]});
		tripletList.push_back({node_1, node_2, LocalMassMat[1][2]});
		tripletList.push_back({node_2, node_0, LocalMassMat[2][0]});
		tripletList.push_back({node_2, node_1, LocalMassMat[2][1]});
		tripletList.push_back({node_2, node_2, LocalMassMat[2][2]});

		GlobalForceVec[node_0] += ElementForceVec[0];
		GlobalForceVec[node_1] += ElementForceVec[1];
		GlobalForceVec[node_2] += ElementForceVec[2];
		
		ElementMeshSize[i/3] = GetElementMeshSize(nodal_coords);

	}
	GlobalMassMat.setFromTriplets(tripletList.begin(), tripletList.end());
	
	double GlobalMeshSize = *max_element(ElementMeshSize, ElementMeshSize + nElements);
	cout << "Global Mesh Size = " << GlobalMeshSize << endl;

// Implementing Dirichlet Boundary Conditions, 
//	u = 0 at the Boundary Nodes for Part A

// Implementing Dirichlet Boundary Conditions,	 
// u = 0 at y = -1, u = 1 at y = 1;
// u = (y + 1)/2 at x = 1, u = (y + 1)/2 at x = -1	
	
	for(int i = 0; i < nNodes; i++)
	{
		double node_coordinates[2] = {coordinates.at(2*i), coordinates.at(2*i+1)};	
		if(CheckBoundaryNode(node_coordinates))
		{

//			Uncomment for FEM Soln not belonging to space of affine functions
			GlobalForceVec[i] = 0.0; 

/*
//			Uncomment for Part B(i)
//			If FEM Soln belonging to space of affine functions			

			if(abs(node_coordinates[0] + 1) < 1e-8 || abs(node_coordinates[0] - 1) < 1e-8) 
				GlobalForceVec[i] = (node_coordinates[1] + 1.0)/2.0;
			
			else if(abs(node_coordinates[1] + 1) < 1e-8)
				GlobalForceVec[i] = 0.0;			
			
			else if(abs(node_coordinates[1] - 1) < 1e-8)
				GlobalForceVec[i] = 1.0;
*/
		}
	}

	for(int j = 0; j < GlobalMassMat.outerSize(); ++j)
	{
		for(SparseMatrix<double, Eigen::RowMajor>::InnerIterator it(GlobalMassMat, j); it; ++it)
		{
			int node = it.row();
			double node_coordinates[2] = {coordinates.at(2*node), coordinates.at(2*node+1)};	
			if(CheckBoundaryNode(node_coordinates))
			{	
				if(it.col() != node)
					it.valueRef() = 0.0;
				else
					it.valueRef() = 1.0;
			}
		}
	}

	SparseLU<SparseMatrix<double> > solver;
	solver.compute(GlobalMassMat);
	Soln = solver.solve(GlobalForceVec);

	fstream OutputFile;
	OutputFile.open("OutputFile", ios::out);
	if(!OutputFile)
		cout << "Output file not created!";
	else
	{
		OutputFile << Soln;
		OutputFile.close();
	}

//  Part B(i)

/*	
	double U, AbsErrorSquare = 0.0;
	for(int i = 0; i < nNodes; i++)
	{
		U = (1.0 + coordinates.at(2*i + 1))/2.0;
		cout << "At coordinates (" << coordinates.at(2*i) << "," << coordinates.at(2*i+1) << ")" << endl;
		cout << "U = " << U << " Uh = " << Soln(i) << endl;
		AbsErrorSquare += (U - Soln(i)) * (U - Soln(i));
	}
	cout << "Absoulute Error square is = " << AbsErrorSquare << endl;
*/

//  Part B(ii) & B(iii): Computing Apriori error ||u - uh||, Energy norm error, |||Grad(u - uh)|||
//	and |||Grad(u - PI U)|||
	
	
	double AprioriErrorSquare = 0.0;
	double AprioriError;
	double ErrorEnergyNormSquare_Uh = 0.0;
	double ErrorEnergyNorm_Uh;
	double ErrorEnergyNormSquare_PiU = 0.0;
	double ErrorEnergyNorm_PiU;
	double Functional_Uh = 0.0;
	double Functional_PiU = 0.0;
	double Functional_Uexact = 0.0;

	VectorXd alpha_piU(nNodes);
	for(int i = 0; i < nNodes; i++)
		alpha_piU(i) = ComputeAlphaPiU_F2(coordinates.at(2*i), coordinates.at(2*i+1));
	
	for(int i = 0; i < connectivity.size(); i += 3)
	{
		int node_0 = connectivity.at(i);
		int node_1 = connectivity.at(i+1);
		int node_2 = connectivity.at(i+2);

		double nodal_coords[6] = {
									coordinates.at(2*node_0), coordinates.at(2*node_0+1),
									coordinates.at(2*node_1), coordinates.at(2*node_1+1),
									coordinates.at(2*node_2), coordinates.at(2*node_2+1)
					   			 };  

		double alpha_nodes[3] = {Soln(node_0), Soln(node_1), Soln(node_2)};
		double pi_alpha_nodes[3] = {alpha_piU(node_0), alpha_piU(node_1), alpha_piU(node_2)};

		AprioriErrorSquare += ComputeGaussQuad_AprioriError(nodal_coords, alpha_nodes);
		ErrorEnergyNormSquare_Uh += ComputeGaussQuad_EnergyNorm_Uh(nodal_coords, alpha_nodes);
		ErrorEnergyNormSquare_PiU += ComputeGaussQuad_EnergyNorm_PiU(nodal_coords, pi_alpha_nodes);

		ComputeGaussQuad_Functional(nodal_coords, alpha_nodes, pi_alpha_nodes, Functional_Uh, Functional_PiU, Functional_Uexact);
	}
	
	ErrorEnergyNorm_Uh = sqrt(ErrorEnergyNormSquare_Uh);
	ErrorEnergyNorm_PiU = sqrt(ErrorEnergyNormSquare_PiU);
	AprioriError = sqrt(AprioriErrorSquare);
	
	
	cout << "Apriori Error = " << AprioriError << endl;
	cout << "Energy Norm Error in Uh = " << ErrorEnergyNorm_Uh << endl;
	cout << "Energy Norm Error in PiU = " << ErrorEnergyNorm_PiU << endl;

	cout << "Value of Functional (0.5*Grad(Uexact))^2 - f*Uexact = " << Functional_Uexact << endl; 
	cout << "Value of Functional (0.5*Grad(Uh))^2 - f*Uh = " << Functional_Uh << endl;
	cout << "Value of Functional (0.5*Grad(PiU))^2 - f*PiU = " << Functional_PiU << endl;

	return 0;
}
