#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
typedef struct mystruct
{
    bool operator()(pair<double,double> a,pair<double,double> b)
    {
        return (a.first < b.first);
    }
}mystruct;
int main()
{
    vector<pair<double,double>> times = {{2,2.3},{3,3.20},{5,5.20},{3.50,4},{2.10,3.40},{3.20,4.30}};
    
    mystruct customComp;
    sort(times.begin(),times.end(),customComp);

    priority_queue<double> min_heap;
    min_heap.push((-1)*times[0].second);

    for(int i=1;i<times.size();i++)
    {

        if((-1*min_heap.top()) <= times[i].first)
        {
            min_heap.pop();
            
        }
        
        min_heap.push(-1*times[i].second);
        
    }

    cout<<"Minimum number of platforms needed to avoid delay is: "<<min_heap.size()<<endl;
}
