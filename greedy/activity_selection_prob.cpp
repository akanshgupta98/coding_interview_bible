#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct mystruct
{
    bool operator()(pair<int,int> a,pair<int,int> b)
    {
        return ( a.second < b.second);
    }
};

int main()
{
    vector<pair<int,int>> activites = {{3,4},{8,9},{0,6},{1,2},{5,7},{5,9}};

    struct mystruct customComp;
    sort(activites.begin(),activites.end(),customComp);
    #ifdef DEBUG
        cout<<"Activities sorted based on finsih time: \n";
        for(auto i: activites)
        {
            cout<<i.first<<" | "<<i.second<<endl;
        }
    #endif
    int number_of_activities = 1;
    pair<int,int>* current_activity = NULL;
    pair<int,int>* last_activity = NULL;


    for(int i=0;i<activites.size();i++)
    {
        current_activity = &activites[i];
        
        

        if(last_activity != NULL)
        {
            #ifdef DEBUG
                cout<<"Position pointed by current: "<<current_activity->first<<endl;
                
                cout<<"Position pointed by last: "<<last_activity->first<<endl;
            #endif
            if(current_activity->first > last_activity->second )
            {

                number_of_activities++;
                last_activity = &activites[i];
            }
            
        }
        else
            last_activity = &activites[i];
        

    }

    cout<<"The maximum number of acitivities I can perform is: "<<number_of_activities<<endl;
    return 0;

}