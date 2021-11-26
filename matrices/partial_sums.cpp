#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<vector<long long>> matrix
    {
        {1,7,12,10,1,0},
        {11,7,-10,1,3,13},
        {-2,9,-5,2,4,7},
        {4,14,-9,3,13,-6},
        {-7,-8,-9,12,6,4},
        {2,-13,10,11,8,7}
        
    };

    vector<vector<long long>> sum_mat = matrix;
    int sum = 0;
    for(int j=0;j<matrix[0].size();j++)
    {
        sum += matrix[0][j];
        sum_mat[0][j] = sum;
    }
    sum = 0;
    for(int i=0;i<matrix.size();i++)
    {
        sum += matrix[i][0];
        sum_mat[i][0] = sum;
    }
    
    for(int i=1;i<matrix.size();i++)
    {
        
        for(int j=1;j<matrix[i].size();j++)
        {
            
            sum_mat[i][j] =   sum_mat[i][j-1] + sum_mat[i-1][j] + matrix[i][j] - sum_mat[i-1][j-1];
        }
    }

    for(auto i: sum_mat)
    {
        for(auto j: i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    cout<<"Partial Sum Query Formula (i1,j1,i2,j2)  = s[i2][j2] - s[i1-1][j2] - s[i2][j2-1] + s[i1-1][j1-1]"<<endl;

    

    return 0;
}