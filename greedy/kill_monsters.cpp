#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    vector<int> monsters = {-3,2,3,-2,8,8,6,4,3,3};
    int health_points = 10;
    int magic_potions = 2;
    priority_queue<int> max_heap;
    int monsters_killed = 0;
    
    cout<<"The maximum number of monsters I can kill with health: "<<health_points<<" and "<<magic_potions<<" magic potions are: ";

    for(int i=0;i<monsters.size();i++)
    {
        if(health_points <= 0)
        {
            break;
        }
        if(monsters[i] < 0)
        {
            health_points += -1*monsters[i];
            
        }
        else
        {
            health_points -= monsters[i];
            max_heap.push(monsters[i]);
            if(health_points <= 0 && magic_potions > 0)
            {
                health_points += max_heap.top();
                magic_potions--;
                max_heap.pop();
            }
            
        }
        monsters_killed++;
    }
    cout<<monsters_killed<<endl;


    
    return 0;
}