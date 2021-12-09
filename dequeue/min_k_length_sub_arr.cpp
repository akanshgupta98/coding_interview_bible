#include<iostream>
#include<deque>
#include<vector>

using namespace std;

int main()
{
    vector<int> arr = {-7,9,2,4,-1,5,6,7,1};
    deque<pair<int,int>> mydeque;
    int k = 3;

    for(int i=0;i<arr.size();i++)
    {   
           
            if(i >= k)
            {
                cout<<"Minimum element in sub-array with start: "<<i - k<<" , end: "<<i<<" is: "<<mydeque.front().first<<endl;
            }
            if(mydeque.front().second == i-k )
            {
                
                mydeque.pop_front();                

            }
            
            
        

        if(mydeque.empty())
        {
            pair<int,int> temp;
            temp = make_pair(arr[i],i);
            mydeque.push_front(temp);
            continue;
        }

        if(mydeque.back().first < arr[i])
        {
            pair<int,int> temp;
            temp = make_pair(arr[i],i);
            mydeque.push_back(temp);
            
        }
        else
        {
            while(mydeque.back().first > arr[i] )
            {
                mydeque.pop_back();
                if(mydeque.empty())
                {
                    break;
                }
            }
            pair<int,int> temp;
            temp = make_pair(arr[i],i);
            mydeque.push_back(temp);
        }
    }
    if(!mydeque.empty())
    {
        cout<<"Minimum element in sub-array with start: "<<arr.size() - k<<" , end: "<<arr.size()-1<<" is: "<<mydeque.front().first<<endl;
    }
    
    return 0;
}