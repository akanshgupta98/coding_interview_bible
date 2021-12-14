#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> arr = {10,5,8,12,15,18,20,17,19};

    vector<int> dp(arr.size());
    dp[0] = 1;

    for(int i=1;i<arr.size();i++)
    {
        int max_lis = 0;
        for(int j=0;j<i;j++)
        {
            if(arr[j] < arr[i])
            {
                max_lis =  max(max_lis,dp[j]);
            }
        }
        dp[i] = 1 + max_lis;

    }

    cout<<"The longest increasing subsequence length is: "<<*max_element(dp.begin(),dp.end())<<endl;

    
    return 0;
}