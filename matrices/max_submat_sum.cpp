#include<iostream>
#include<vector>

using namespace std;

long long max_sub_arr(vector<long long>& );

int main()
{
    vector<vector<long long>> matrix
    {
        {1,2,-1,-4,-20},
        {-8,-3,4,2,1},
        {3,8,10,1,3},
        {-4,-1,1,7,-6}
        
    };
    vector<vector<long long>> upsum = matrix;
    

    cout<<"Original matrix is: \n";
    for(auto i: matrix)
    {
        for(auto j: i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    

    for(int i=1;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[i].size();j++)
        {
            upsum[i][j] = upsum[i-1][j] + upsum[i][j]; 
        }
    }

    #ifdef DEBUG

        cout<<"Upsum matrix is: \n";
        for(auto i: upsum)
        {
            for(auto j: i)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    #endif
    long long ans = 0;
    for(int r1=0;r1<matrix.size();r1++)
    {
        for(int r2 = r1;r2<matrix.size();r2++)
        {
            vector<long long> temp;
            for(int i=0;i<matrix[r1].size();i++)
            {
                if(r1-1 >= 0)
                    temp.push_back(upsum[r2][i] - upsum[r1-1][i]);
                else
                    temp.push_back(upsum[r2][i]);
            }
          #ifdef DEBUG
                cout<<"Temp array is: \n";
                for(auto i: temp)
                {
                    cout<<i<<" ";   
                }
                cout<<endl;
            #endif  

            ans = max(ans,max_sub_arr(temp));
        }
    }
    cout<<"Maximum sum sub-matrix is: "<<ans<<endl;

    return 0;
}

long long max_sub_arr(vector<long long>& arr)
{

    long long run_sum = 0;
    long long max_sum = 0;

    for(int i=0;i<arr.size();i++)
    {
        run_sum += arr[i];

        if(max_sum < run_sum)
        {
            max_sum = run_sum;
        }

        if(run_sum < 0)
        {
            run_sum = 0;
        }

        
    }
    return max_sum;
}