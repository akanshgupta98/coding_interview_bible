#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{

    vector<int> main_arr = {1,2,3,4,2,4};
    vector<int> freq_arr( (*max_element(main_arr.begin(),main_arr.end()) )+1,0);

    for(auto i: main_arr)
    {
        freq_arr[i]++;
    }

    cout<<"Count of 3 in this array is: "<<freq_arr[3]<<endl;

    return 0;
}