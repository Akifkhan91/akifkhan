OBJECTS = HW5.o ReadMesh.o GetElementMeshSize.o ComputeDistance.o CheckBoundaryNode.o GetDetJacobian.o \
		  GetJacobianInv.o GetGradFunction.o ComputeElementMassMatrix.o GetFunctionVal_F1.o \
		  GetFunctionVal_F2.o Compute_UExact_F2.o ComputeGaussQuad_AprioriError.o Compute_Uh.o ComputeGaussQuad.o \
		  Compute_UExact_F1.o Compute_Grad_UExact_F2.o ComputeGaussQuad_EnergyNorm_Uh.o Compute_Grad_UExact_F1.o \
		  ComputeAlphaPiU_F2.o ComputeGaussQuad_EnergyNorm_PiU.o ComputeAlphaPiU_F1.o ComputeGaussQuad_Functional.o \
		  Compute_f_F1.o Compute_f_F2.o 
		  
HW5 : $(OBJECTS)
	g++ -std=c++11 -o HW5 $(OBJECTS)

HW5.o : HW5.cpp HeaderFile.h
	g++ -std=c++11 -c HW5.cpp	

ReadMesh.o : ReadMesh.cpp HeaderFile.h
	g++ -std=c++11 -c ReadMesh.cpp	

GetElementMeshSize.o : GetElementMeshSize.cpp HeaderFile.h
	g++ -std=c++11 -c GetElementMeshSize.cpp	

ComputeDistance.o : ComputeDistance.cpp HeaderFile.h
	g++ -std=c++11 -c ComputeDistance.cpp

CheckBoundaryNode.o : CheckBoundaryNode.cpp HeaderFile.h
	g++ -std=c++11 -c CheckBoundaryNode.cpp	

GetDetJacobian.o : GetDetJacobian.cpp HeaderFile.h
	g++ -std=c++11 -c GetDetJacobian.cpp	

GetJacobianInv.o : GetJacobianInv.cpp HeaderFile.h
	g++ -std=c++11 -c GetJacobianInv.cpp		

GetGradFunction.o : GetGradFunction.cpp HeaderFile.h
	g++ -std=c++11 -c GetGradFunction.cpp	

ComputeElementMassMatrix.o : ComputeElementMassMatrix.cpp HeaderFile.h
	g++ -std=c++11 -c ComputeElementMassMatrix.cpp	

GetFunctionVal_F1.o : GetFunctionVal_F1.cpp HeaderFile.h
	g++ -std=c++11 -c GetFunctionVal_F1.cpp	

GetFunctionVal_F2.o : GetFunctionVal_F2.cpp HeaderFile.h
	g++ -std=c++11 -c GetFunctionVal_F2.cpp		

Compute_UExact_F2.o : Compute_UExact_F2.cpp HeaderFile.h
	g++ -std=c++11 -c Compute_UExact_F2.cpp

ComputeGaussQuad_AprioriError.o : ComputeGaussQuad_AprioriError.cpp HeaderFile.h
	g++ -std=c++11 -c ComputeGaussQuad_AprioriError.cpp		

Compute_Uh.o : Compute_Uh.cpp HeaderFile.h
	g++ -std=c++11 -c Compute_Uh.cpp

ComputeGaussQuad.o : ComputeGaussQuad.cpp HeaderFile.h
	g++ -std=c++11 -c ComputeGaussQuad.cpp

Compute_UExact_F1.o : Compute_UExact_F1.cpp HeaderFile.h
	g++ -std=c++11 -c Compute_UExact_F1.cpp

Compute_Grad_UExact_F2.o : Compute_Grad_UExact_F2.cpp HeaderFile.h
	g++ -std=c++11 -c Compute_Grad_UExact_F2.cpp

ComputeGaussQuad_EnergyNorm_Uh.o : ComputeGaussQuad_EnergyNorm_Uh.cpp HeaderFile.h
	g++ -std=c++11 -c ComputeGaussQuad_EnergyNorm_Uh.cpp

Compute_Grad_UExact_F1.o : Compute_Grad_UExact_F1.cpp HeaderFile.h
	g++ -std=c++11 -c Compute_Grad_UExact_F1.cpp

ComputeAlphaPiU_F2.o : ComputeAlphaPiU_F2.cpp HeaderFile.h
	g++ -std=c++11 -c ComputeAlphaPiU_F2.cpp

ComputeGaussQuad_EnergyNorm_PiU.o : ComputeGaussQuad_EnergyNorm_PiU.cpp HeaderFile.h
	g++ -std=c++11 -c ComputeGaussQuad_EnergyNorm_PiU.cpp

ComputeAlphaPiU_F1.o : ComputeAlphaPiU_F1.cpp HeaderFile.h
	g++ -std=c++11 -c ComputeAlphaPiU_F1.cpp

ComputeGaussQuad_Functional.o : ComputeGaussQuad_Functional.cpp HeaderFile.h
	g++ -std=c++11 -c ComputeGaussQuad_Functional.cpp

Compute_f_F1.o : Compute_f_F1.cpp HeaderFile.h
	g++ -std=c++11 -c Compute_f_F1.cpp

Compute_f_F2.o : Compute_f_F2.cpp HeaderFile.h
	g++ -std=c++11 -c Compute_f_F2.cpp

clean :
	rm myprogram \
	$(OBJECTS)