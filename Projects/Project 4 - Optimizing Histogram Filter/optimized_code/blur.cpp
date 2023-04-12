#include "headers/blur.h"

using namespace std;

vector < vector <float> > blur(vector < vector < float> >& grid, float blurring) {

	// initialize variables
  	int height;
	int width;
	float center, corner, adjacent;

	height = grid.size();
	width = grid[0].size();
	vector < vector <float> > newGrid;
	vector <float> row;
	vector <float> newRow;
  	newGrid.reserve(height);
  	newRow.reserve(width);



	// calculate blur factors
	center = 1.0 - blurring;
	corner = blurring / 12.0;
	adjacent = blurring / 6.0;

	int i, j;
  	// 2D vector reprenting the blur filter
	vector < vector <float> > window = {
            {corner,  adjacent,  corner},
            {adjacent, center,  adjacent},
            {corner,  adjacent,  corner}
	};

	// variables for blur calculations
  	vector <int> DX = {-1,0,1};
	vector <int> DY = {-1,0,1};

	int ii;
	int jj;
	int new_i;
	int new_j;

	// initialize new grid to zeros
  	for (j=0; j<width; j++) 
    {
		newRow.push_back(0.0);
	}
	for (i=0; i<height; i++) 
    {		
		newGrid.push_back(newRow);
	}

	// blur the grid and store in a new 2D vector
	for (i=0; i< height; i++ ) {
		for (j=0; j<width; j++ ) {
			for (ii=0; ii<3; ii++) {
				for (jj=0; jj<3; jj++) {
					new_i = (i + DY[ii] + height) % height;
					new_j = (j + DX[jj] + width) % width;
					newGrid[new_i][new_j] += grid[i][j] * window[ii][jj];
				}
			}
		}
	}

	return newGrid;
}
