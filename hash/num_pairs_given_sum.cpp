#include<iostream>
#include<unordered_map>

#include<vector>

using namespace std;

int main()
{
    vector<int> arr = {3,-2,9,3,-2,4,9};
    int req_sum = 7;
    int ans = 0;
    unordered_map<int,int> myset;

    for(int i=0;i<arr.size();i++)
    {
        if(myset.empty())
        {
            myset[req_sum - arr[i]]++;

        }
        else
        {
            if(myset.find(arr[i]) != myset.end())
            {
                cout<<"("<<arr[i]<<" + "<<req_sum - arr[i]<<")"<<endl;
                ans += myset[arr[i]];
            }
            
            
            myset[req_sum - arr[i]]++;
            
        }
    }

    cout<<"Pairs with sum as "<<req_sum<<" are: "<<ans<<endl;
    return 0;
}