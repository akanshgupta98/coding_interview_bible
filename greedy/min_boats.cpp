#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
    vector<int> arr = {31,32,34,45,51,55,72,81,88,93};
    vector<bool> visited(arr.size(),false);

    sort(arr.begin(),arr.end());
    priority_queue<pair<int,int>> max_heap;
    int max_weight_boat = 100;
    int absolute_diff_acceptabe = 10;
    int num_boats = 0;

    int i = 0;

    for(int j=arr.size()-1;j>=0;j--)
    {
        cout<<"checking for: "<<arr[j]<<endl;
        
        if(visited[j])
        {
            continue;
        }
        visited[j] = true;
        
        while( i < j && (arr[i] + arr[j] <= max_weight_boat))
        {    
            max_heap.push({arr[i],i++});
            
        }
        if(!max_heap.empty())
        {
            while( (arr[j] - max_heap.top().first) <= absolute_diff_acceptabe)
            {
                
                if(!visited[max_heap.top().second])
                {
                    visited[max_heap.top().second] = true;
                    max_heap.pop();
                    break;
                    
                }
                max_heap.pop();
                if(max_heap.empty())
                {
                    break;
                }
            }
            
        }
        num_boats++;
        cout<<"num boats: "<<num_boats<<endl;

    }

    cout<<"Minimum number of boats required are: "<<num_boats<<endl;


    return 0;
}