#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define MYMAX (1000000)
#define MYMIN (-1000000)

bool isValid(int,vector<vector<int>>&);
int main()
{
    vector<vector<int>> points
    {
        {1,3},
        {2,1},
        {4,0},
        {3,2},
        {5,4}
    };

    int start = 0;
    int end = MYMAX;
    int distance;
    sort(points.begin(),points.end());
    
    #ifdef DEBUG
    cout<<"Sorted points are: \n";
    for(auto i: points)
    {
        for(auto j : i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    #endif
    int result = 0;

    while(start < end)
    {
        distance = (start + end)/2;
        
        #ifdef DEBUG
            
            cout<<"Start is: "<<start<<" End is: "<<end<<" Distance is: "<<distance;
        
        #endif

        if(isValid(distance,points))
        {
        
            #ifdef DEBUG
                cout<<" Valid\n";
            
            #endif
        
            result = distance;
            start = distance+1;
        }
        else
        {
        
            #ifdef DEBUG
                cout<<" Invalid\n";
            
            #endif
            end = distance;
        }
    }
    

    cout<<"Maximum distance is: "<<result<<endl;

    return 0;
}

bool isValid(int dist,vector<vector<int>>& points)
{
    int i = -1;
    int min_y = MYMAX;
    int max_y = MYMIN;
    int x_i,x_j,y_i,y_j;

    for(int j=1;j < points.size();j++)
    {
        x_j = points[j][0];
        y_j = points[j][1];
        
        while(i+1 < j )
        {
            
            x_i = points[i+1][0];
            
            if(x_j - x_i >= dist)
            {
                i++;
                y_i = points[i][1];
                min_y = min(min_y,y_i);
                max_y = max(max_y,y_i);

            }
            else
            {
                break;
            }

        }
        
        if( i != -1 && abs(y_j - min_y) >= dist )
        {
            return true;
        }

        if( i != -1 && abs(y_j - max_y) >= dist )
        {
            return true;
        }
    
    }
    
    return false;
}