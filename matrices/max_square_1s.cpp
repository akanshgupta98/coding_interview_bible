#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<long long>> create_partial_sum_mat(vector<vector<long long>>&);
long long get_max_square_1s(vector<vector<long long>>& matrix,vector<vector<long long>>& sum_mat);



int main()
{
    vector<vector<long long>> matrix
    {
        {1,1,1,1,1},
        {1,1,1,1,1},
        {1,1,1,1,1},
        {1,1,1,1,1}
        
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

    vector<vector<long long>> sum_mat = create_partial_sum_mat(matrix);
    vector<vector<long long>> max_len = matrix;
    
    #ifdef DEBUG
        cout<<"Partial Sum matrix is: \n";
        for(auto i: sum_mat)
        {
            for(auto j: i)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    #endif

    long long max_result = 0;
    #ifdef BRUTE
        max_result = get_max_square_1s(matrix,sum_mat);
    #endif

    max_result = get_max_square_1s(matrix,max_len);


    cout<<"Maximum size of square full of 1s is: "<<max_result<<endl;

    return 0;
}

vector<vector<long long>> create_partial_sum_mat(vector<vector<long long>>& matrix)
{
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
    return sum_mat;
}


long long get_max_square_1s(vector<vector<long long>>& matrix,vector<vector<long long>>& sum_mat)
{
    #ifdef BRUTE
        int max_result = 0;
        for(int r1 = 0;r1<matrix.size();r1++)
        {
            for(int c1 = 0;c1 < matrix[r1].size();c1++)
            {
                if(matrix[r1][c1] == 1)
                {
                    int result = 1;
                    for(int i=1;i<matrix[i].size();i++)
                    {
                        int r2 = r1 - i;
                        int c2 = c1 - i;

                        #ifdef DEBUG
                        
                            if(r2 >= 0 & c2 >= 0)
                            {
                                cout<<"Bottom corner: ("<<r1<<","<<c1<<")\n";
                            
                                cout<<"Upper corner: ("<<r2<<","<<c2<<")\n";
                            }

                        #endif

                        int par_sum = 0;
                        if(r2-1 >= 0 && c2-1 >=0)
                        {
                            par_sum = sum_mat[r1][c1] - sum_mat[r2-1][c1] - sum_mat[r1][c2-1] + sum_mat[r2-1][c2-1];
                            
                            
                        }
                        else if(r2-1 < 0 && c2-1 >=0)
                        {
                            par_sum = sum_mat[r1][c1] - sum_mat[r1][c2-1] ;
                        }
                        else if(c2-1 <0 && r2-1 >=0)
                        {
                            par_sum = sum_mat[r1][c1] - sum_mat[r2-1][c1];
                        }
                        else if(c2-1 < 0 && r2 - 1 <0)
                        {
                            par_sum = sum_mat[r1][c1];
                        }

                            #ifdef DEBUG
                            if(r2 >=0 && c2 >=0)
                                cout<<"Square sum is: "<<par_sum<<endl;
                            #endif
                            if(par_sum == (i+1)*(i+1) )
                            {
                                result++;
                            }
                        
                        if(r2 < 0  || c2 < 0)
                        {
                            break;
                        }
                    }
                    max_result = max(max_result,result);
                }
            }
        }
        return max_result;
    #endif
    long long max_result = 0;

    for(int r1 = 1;r1<matrix.size();r1++)
    {
        for(int c1 = 0;c1 < matrix[r1].size();c1++)
        {
            if(matrix[r1][c1] == 1)
            {
                if(r1-1 >=0 && c1-1 >=0)
                {
                    long long temp = min(sum_mat[r1-1][c1],sum_mat[r1][c1-1]);

                    sum_mat[r1][c1] = 1 + min(temp,sum_mat[r1-1][c1-1]);
                }
                    
                else if(r1-1 < 0 && c1-1 >=0 )
                    sum_mat[r1][c1] = 1 + sum_mat[r1][c1-1];
                else if(r1-1 >=0 && c1-1 <0)
                    sum_mat[r1][c1] = 1 + sum_mat[r1-1][c1];
                else
                    sum_mat[r1][c1] = 1;
                
                
                
                max_result = max(max_result,sum_mat[r1][c1]);
            }
            else
            {
                sum_mat[r1][c1] = 0;
            }
        }
    }
    #ifdef DEBUG
        cout<<"Max Length Matrix is: \n";
        for(auto i: sum_mat)
        {
            for(auto j: i)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    #endif
    return max_result;
}


    