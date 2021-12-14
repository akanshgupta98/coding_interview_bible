#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
typedef vector<int>::iterator it;
it mysearch(it start,it end,int);
int main()
{
    vector<int> a = {1,7,1,8,3,6,5,9};
    vector<int> b = {7,3,9,8};
    vector<pair<int,int>> dp(b.size());
    dp[0] = {1,mysearch(a.begin(),a.end(),b[0]) - a.begin()};
    cout<<dp[0].first<<" | "<<dp[0].second<<endl;
    for(int i=1;i<b.size();i++)
    {
        int pos = mysearch(a.begin(),a.end(),b[i]) - a.begin();
        cout<<"POS: "<<pos<<endl;
        int max_lcs = 0;
        for(int j = 0;j< i;j++)
        {
            cout<<dp[j].first<<" | "<<dp[j].second<<endl;

            if(dp[j].second < pos )
            {
                max_lcs = max(max_lcs,dp[j].first);
            }

        }
        dp[i] = {1+max_lcs,pos};
    }

    cout<<"LCS is: "<<(*max_element(dp.begin(),dp.end())).first<<endl;
    

    return 0;
}
it mysearch(it start,it end,int element)
{
    while(start < end)
    {
        if(*(start) == element)
        {
            return start;
        }
        start++;
    }
    return end;

}