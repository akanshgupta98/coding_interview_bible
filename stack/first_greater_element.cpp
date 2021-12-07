#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main()
{

    vector<int> arr = {7,3,2,6,11,9,8,10,13};
    vector<int> greater_index(arr.size(),-1);
    stack<int> mystack;

    cout<<"Given array is: \n";
    for(auto i: arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    for(int i = 0;i < arr.size();i++)
    {
        if(mystack.empty())
        {
            mystack.push(i);
        }

        else
        {
            if(arr[mystack.top()] > arr[i])
            {
                mystack.push(i);
            }

            else
            {
                while(arr[mystack.top()] < arr[i])
                {
                    greater_index[mystack.top()] = i;
                    mystack.pop();
                    if(mystack.empty())
                    {   
                        
                        break;
                    }
                }
                mystack.push(i);    
            }
        }
    }

    for(int i=0;i<arr.size();i++)
    {
        if(greater_index[i] == -1)
        {
            cout<<"First greater element for "<<arr[i]<<" : Greatest Element\n";
        }
        else
        {
            cout<<"First greater element for "<<arr[i]<<" : "<<arr[greater_index[i]]<<"\n";
        }
    }
    
    return 0;
}