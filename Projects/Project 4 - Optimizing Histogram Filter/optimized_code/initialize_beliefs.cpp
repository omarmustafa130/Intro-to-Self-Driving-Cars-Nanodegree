#include "headers/initialize_beliefs.h"

using namespace std;

vector< vector <float> > initialize_beliefs(vector< vector <char> >& grid) {

	// initialize variables for new grid
  	int i, j, height, width;
	height = grid.size();
	width = grid[0].size();
	vector< vector <float> > newGrid;
	vector<float> newRow;
  	newGrid.reserve(height);
  	newRow.reserve(width);
  
	// store initial values in a new 2D grid with same size as grid
  	for (j=0; j<width; j++) 
    {
		newRow.push_back(1.0 / ( (float) height*width));
	}	
	for (i=0; i<height; i++) 
    {		
		newGrid.push_back(newRow);
	}
	return newGrid;
}