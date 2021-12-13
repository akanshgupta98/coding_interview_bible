#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct mycomparator
{
    bool operator() (pair<double,int> a,pair<double,int> b)
    {
        return( a.first > b.first);
    }
};

int main()
{

    vector<double> values = {10,5,15,7,6,18,3};
    vector<double> weights = {2,3,5,7,1,4,1};

    vector<pair<double,int>> val_per_weight;

    auto i = values.begin();
    auto j = weights.begin();
    int index = 0;
    while(i < values.end())
    {
        pair<double,int> temp;
        temp.first = (*i)/(*j);
        temp.second = *j; 
        val_per_weight.push_back(temp);
        i++;
        j++;
    }
    int capacity_of_knapsack = 10;
    int fill_knapsack = 0;
    int result = 0;
    struct mycomparator myfunctor;
    sort(val_per_weight.begin(),val_per_weight.end(),myfunctor);
    #ifdef DEBUG
        cout<<"VALUE PER WEIGHT ARRAY IS: \n";
        for(auto i: val_per_weight)
        {
            cout<<i.first<<"|"<<i.second<<endl;
        }
        cout<<endl;
    #endif

    for(int i=0;i<values.size();i++)
    {
        if(capacity_of_knapsack <= 0)
        {
            break;
        }

        if(val_per_weight[i].second <= capacity_of_knapsack)
        {
            result += (val_per_weight[i].first * val_per_weight[i].second);
            fill_knapsack += val_per_weight[i].second;
            capacity_of_knapsack -= val_per_weight[i].second;
        }
            
        else
        {
            result += (val_per_weight[i].first * (capacity_of_knapsack));
            fill_knapsack += capacity_of_knapsack;
            capacity_of_knapsack -= capacity_of_knapsack;

        }
        
        
        
    }

    cout<<"Maximum values with I can fill my knapsack of capacity "<<fill_knapsack<<" is: "<<result<<endl;

    return 0;
}