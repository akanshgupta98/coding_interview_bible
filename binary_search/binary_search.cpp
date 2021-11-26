#include<iostream>
#include<vector>
#include<numeric>
#include<iterator>


using namespace std;
typedef vector<int>:: iterator it;
bool my_binary_search(it ,it ,int);
int main()
{
    vector<int> arr(15);
    iota(arr.begin(),arr.end(),1);
    
    cout<<"Original Array is: \n";
    for(auto i: arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    int num = 15;
    (my_binary_search(arr.begin(),arr.end(),num)? cout<<"Found: "<<num<<"\n": cout<<"Not Found: "<<num<<"\n");


    return 0;
}
bool my_binary_search(it start ,it end ,int val)
{

    if(start < end)
    {
        it mid = (start + distance(start,end)/2);
        
        if(*mid == val)
        {
            return 1;
        }
        if(*mid < val)
        {
            return( my_binary_search(mid+1,end,val));

        }
        else
            return( my_binary_search(start,mid,val));

    }
    return 0;
}
