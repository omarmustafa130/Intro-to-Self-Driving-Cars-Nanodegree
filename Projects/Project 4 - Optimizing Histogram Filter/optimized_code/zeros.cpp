#include "headers/zeros.h"

using namespace std;

vector < vector <float> > zeros(int& height, int& width) {
	int i, j;
	vector < vector <float> > newGrid;
	vector <float> newRow;
	newGrid.reserve(height);
  	newRow.reserve(width);
  	for (j=0; j<width; j++) 
    {
		newRow.push_back(0.0);
	}
	for (i=0; i<height; i++) 
    {		
		newGrid.push_back(newRow);
	}
	return newGrid;
}