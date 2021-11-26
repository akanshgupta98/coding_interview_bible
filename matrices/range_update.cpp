#include<iostream>
#include<vector>

using namespace std;

void update_mat(int r1,int c1, int r2,int c2,int val, vector<vector<long long>>& );

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

    cout<<"Original matrix is: \n";
    for(auto i: matrix)
    {
        for(auto j: i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    vector<vector<long long>> temp_mat;
    for(int i=0;i<matrix.size();i++)
    {
        vector<long long> temp(matrix[i].size(),0);
        temp_mat.push_back(temp);
    }
    #ifdef DEBUG

        cout<<"TEMP_MAT initial: \n";
        for(auto i: temp_mat)
        {
            for(auto j: i)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    #endif

    update_mat(1,2,3,5,2,temp_mat);
    #ifdef DEBUG

        cout<<"TEMP_MAT after update: \n";
        for(auto i: temp_mat)
        {
            for(auto j: i)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    #endif
    vector<vector<long long>> sum_mat = temp_mat;

    int sum = 0;
    for(int j=0;j<temp_mat[0].size();j++)
    {
        sum += temp_mat[0][j];
        sum_mat[0][j] = sum;
    }
    sum = 0;
    for(int i=0;i<temp_mat.size();i++)
    {
        sum += temp_mat[i][0];
        sum_mat[i][0] = sum;
    }
    for(int i=1;i<sum_mat.size();i++)
    {
        
        for(int j=1;j<sum_mat[i].size();j++)
        {
            
            sum_mat[i][j] =   sum_mat[i][j-1] + sum_mat[i-1][j] + temp_mat[i][j] - sum_mat[i-1][j-1];
        }
    }
    #ifdef DEBUG

        cout<<"SUM_MAT is: \n";
        for(auto i: sum_mat)
        {
            for(auto j: i)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    #endif

    for(int i=0;i<sum_mat.size();i++)
    {
        
        for(int j=0;j<sum_mat[i].size();j++)
        {
            
            matrix[i][j] +=   sum_mat[i][j];
        }
    }

    

    cout<<"Original matrix after update is: \n";
    for(auto i: matrix)
    {
        for(auto j: i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }


    

    


    // for(auto i: sum_mat)
    // {
    //     for(auto j: i)
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    // cout<<"Partial Sum Query Formula (i1,j1,i2,j2)  = s[i2][j2] - s[i1-1][j2] - s[i2][j2-1] + s[i1-1][j1-1]"<<endl;

    

    return 0;
}
void update_mat(int r1,int c1, int r2,int c2,int val, vector<vector<long long>>& sum_mat)
{

    sum_mat[r1][c1] += val;
    if(c2+1 < sum_mat[0].size())
        sum_mat[r1][c2+1] -= val;
    if(r2+1 < sum_mat.size())
        sum_mat[r2+1][c1] -= val;
    if(r2+1 <sum_mat.size() && c2+1 < sum_mat[0].size())
        sum_mat[r2+1][c2+1] += val;

}