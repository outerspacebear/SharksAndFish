#include "stdafx.h"
#include"Grid.h"
#include"GridMPI.h"
#include"GridOMP.h"
#include"GridHybrid.h"
#include"Utils.h"
#include<mpi.h>

#include<iostream>
#include<stdlib.h>

//Whichever mode you want to use should be uncommented and all the others should be commented:
//#define SERIAL
#define OMP
//#define MPI
//#define HYBRID

int main(int argc, char *argv[])
{
	//Set the rows and columns the grid should have, and the number of iterations the test should run for:
	//Once set here, these numbers will be valid for all modes of running (serial, MPI, etc.)
	constexpr int rows = 10;
	constexpr int cols = 20;
	constexpr int nIterations = 5;

	//Initialize utilities before everything else
	Utils::initUtils();


#ifdef SERIAL
	Grid myGrid = Grid(rows, cols);

	//For running the test and recording the time it takes to run:
	std::cout << myGrid.runTest(nIterations) / static_cast<float>(1000) << std::endl;
	//myGrid.showGridAsImage();

	//For going through and displaying it step by step:
	int iteration = 0;
	/*while (true)
	{
		//myGrid.printToConsole('X', 'F', ' ');
		myGrid.calculateNextGridState();
		myGrid.goToNextGridState();
		std::cout << "Generation " << iteration << "\n";
		myGrid.printToConsole();
		system("pause");	
		++iteration;
	}/**/

	
	//myGrid.printStatsToConsole();
	
	system("pause");
#endif

#ifdef OMP
	GridOMP myGrid = GridOMP(rows, cols);

	std::cout << myGrid.runTest(nIterations) / static_cast<float>(1000) << std::endl;
	//myGrid.showGridAsImage();
	
	//system("pause");
#endif

#ifdef MPI
	MPI_Init(&argc, &argv);

	GridMPI myGrid = GridMPI(rows, cols);
	std::cout << myGrid.runTest(nIterations) / static_cast<float>(1000);
	//myGrid.showGridAsImage();
	

	MPI_Finalize();
#endif

#ifdef HYBRID
	MPI_Init(&argc, &argv);

	GridHybrid myGrid = GridHybrid(rows, cols);
	std::cout << myGrid.runTest(nIterations) / static_cast<float>(1000);
	//myGrid.showGridAsImage("Final Grid");

	MPI_Finalize();
#endif

    return 0;
}

