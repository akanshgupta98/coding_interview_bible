#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
typedef string::iterator it;
it mysearch(it start,it end,char);
int main()
{
    string text1 = "abc";
    string text2 = "abcde";
    string a = (text1.size() > text2.size())?(text1):(text2);
    string b = (text1.size() < text2.size())?(text1):(text2);

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

it mysearch(it start,it end,char element)
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