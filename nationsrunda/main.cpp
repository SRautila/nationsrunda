#include <iostream>
#include <array>
#include <fstream>

	int shortestPathLength = 9999999; // Initiates to bs value
	int shortestPathRoute[14];
	
	// All the routes from -> to. Explained in some txt somewhere but first 0.0 is jalla->jalla anyway
	int possiblePaths[14][14] =
	{{0, 1100, 1050, 1880, 2700, 500, 1650, 1670, 980, 2070, 1360, 950, 2210, 1540,},
	{1100, 0, 1790, 1210, 1950, 1190, 780, 1000, 1720, 1080, 1450, 1610, 1280, 2190},
	{1050, 1790, 0, 2000, 2790, 890, 1800, 1780, 690, 2100, 960, 410, 2280, 430},
	{1880, 1210, 2000, 0, 810, 1790, 420, 230, 1710, 250, 1460, 1330, 500, 2430},
	{2700, 1950, 2790, 810, 0, 2580, 1180, 980, 2530, 880, 2250, 3200, 900, 3220},
	{500, 1190, 890, 1790, 2580, 0, 1470, 1650, 890, 1740, 1170, 530, 1950, 1000},
	{1650, 780, 1800, 420, 1180, 1470, 0, 210, 1560, 530, 1300, 1990, 760, 2250},
	{1670, 1000, 1780, 230, 980, 1650, 210, 0, 1510, 510, 1250, 2230, 730, 2280},
	{980, 1720, 690, 1710, 2530, 890, 1560, 1510, 0, 1980, 270, 1060, 2220, 1100},
	{2070, 1080, 2100, 250, 880, 1740, 530, 510, 1980, 0, 1780, 2700, 230, 2750},
	{1360, 1450, 960, 1460, 2250, 1170, 1300, 1250, 270, 1780, 0, 1380, 1970, 1440},
	{950, 1610, 410, 2330, 3200, 530, 1990, 2230, 1060, 2700, 1380, 0, 2500, 460},
	{2210, 1280, 2280, 500, 900, 1950, 760, 730, 2220, 230, 1970, 2500, 0, 2980},
	{1540, 2190, 430, 2430, 3220, 1000, 2250, 2280, 1100, 2750, 1440, 460, 2980, 0}};


void compareWithShortest(int currentPath[])
{
	int currentPathLength = 0;
	for(int i = 0; i < 13; i++)
	{
		currentPathLength = currentPathLength + possiblePaths[currentPath[i]][currentPath[i+1]];
	}

	if (currentPathLength < shortestPathLength) // Checks if current length is shortest
	{
		shortestPathLength = currentPathLength; // Saves current length as shortest
		for (int i = 0; i < 14; i++)
		{
		shortestPathRoute[i] = currentPath[i]; // Saves current path as shortest
		}
		std::cout << "new shortest route: " << shortestPathLength << '\n';
	}
}
	
void findPath(bool used[], int path[], int k)
{
	if (k == 14)
	{
		compareWithShortest(path);
	}

	for(int i = 1; i < 14; i++) // Begins at second element since we alltimes start at Jalla
	{
		if(!used[i])
		{
			path[k] = i;
			used[i] = true;
			findPath(used, path, k+1);
			used[i] = false;
		}
	}
}




int main()
{
	int k = 1;
	int path[14];
	path[0] = 0; // We always start at Jalla
	
	bool used[14];
	for (int i = 0; i < 14; i++)
		used[i] = false;


	findPath(used, path, k);

	std::cout << shortestPathLength << '\n';
	for(int i = 0; i < 14; i++) 
	{
		std::cout << shortestPathRoute[i] << '\n';
	}


	std::cin.ignore();
	std::cin.get();

	return 0;
}

