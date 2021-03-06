#pragma once
#include"Grid.h"

/*Represents a 2D grid made up of cells, each being able to contain a shark, a fish, or water.
These are represented by integers:
> 0 = fish
< 0 = shark
==0 = water
For sharks and fish, the absolute value of the integer corresponds to their age.
eg- A cell with value -5 contains a 5-year-old shark.*/
class GridOMP : public Grid
{
public:
	GridOMP(int rows, int cols) : Grid(rows, cols) {};
	void calculateNextGridState();
	void showGridAsImage(std::string additionalInfo = "");
	float runTest(int nIterations);
};
