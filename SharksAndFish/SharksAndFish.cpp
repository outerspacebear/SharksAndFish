#include "stdafx.h"
#include"Grid.h"
#include"Utils.h"

#include<stdlib.h>

int main()
{
	//Initialize utilities before everything else
	Utils::initUtils();

	Grid myGrid = Grid(100, 100);
	//myGrid.printGridToConsole();
	myGrid.printStatsToConsole();
	
	system("pause");

    return 0;
}

