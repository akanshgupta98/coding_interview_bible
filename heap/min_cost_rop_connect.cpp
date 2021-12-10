#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int cost = 0;
void ropes_join(priority_queue<int>& min_heap);
priority_queue<int> build_min_heap(vector<int>& arr);
int main()
{
    vector<int> arr = {4,3,2,6};

    priority_queue<int> min_heap (build_min_heap(arr));
    

    ropes_join(min_heap);
    cout<<"The minimum cost of joining all ropes is: "<<::cost<<endl;
    
    
    return 0;
}
void ropes_join(priority_queue<int>& min_heap)
{
    if(min_heap.size() == 1)
    {
        return;
    }
    int min_1 = -1 * min_heap.top();
    min_heap.pop();
    int min_2 = -1 * min_heap.top();
    min_heap.pop();
    ::cost += min_1 + min_2;
    min_heap.push( -1*(min_1 + min_2));
    ropes_join(min_heap);
}
priority_queue<int> build_min_heap(vector<int>& arr)
{
    priority_queue<int> min_heap;
    for(int i=0;i<arr.size();i++)
    {
        min_heap.push(-1*arr[i]);
    }
    return min_heap;
}