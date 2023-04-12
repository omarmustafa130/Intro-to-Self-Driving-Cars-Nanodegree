//TODO: Write a function that receives two integer matrices and outputs
// the sum of the two matrices. Then in your main() function, input a few
// examples to check your solution. Output the results of your function to 
// cout. You could even write a separate function that prints an arbitrarily 
// sized matric to cout.

#include<iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrices_sum(vector<vector<int>>matrix1, vector<vector<int>>matrix2)
{

    vector<vector<int>>matrices_sum(matrix1.size(), vector<int> (matrix1[0].size(), 0));
    
    for (int r = 0; r<matrix1.size(); r++) //rows
    {
        for (int c = 0; c<matrix1[0].size(); c++) //coloumns
        {
            matrices_sum[r][c] = matrix1[r][c] + matrix2[r][c];
        }
    }
    

    return matrices_sum;        
}

void print_matrix(vector<vector<int>>matrix)
{
    for (int r = 0; r<matrix.size(); r++) //rows
    {
        for (int c = 0; c<matrix[0].size(); c++) //coloumns
        {
            cout<<matrix[r][c];
        }
        cout<<endl;
    } 
}

int main()
{
    vector<vector<int>>two_d_vector1;
    vector<vector<int>>two_d_vector2;
    vector<vector<int>>two_d_matrix_result;

    vector<int> single_row(3,2);
    for (int i = 0; i<5; i++)
    {
        two_d_vector1.push_back(single_row);
        two_d_vector2.push_back(single_row);
    }
    print_matrix(two_d_vector1);
    cout<<endl;
    print_matrix(two_d_vector2);
    cout<<endl;
    //two_d_matrix_result = matrices_sum(two_d_vector1,two_d_vector2);
    print_matrix(matrices_sum(two_d_vector1,two_d_vector2));
    cout<<endl;
    return 0;
}