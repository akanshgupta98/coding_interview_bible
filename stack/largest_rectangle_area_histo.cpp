#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

typedef vector<int>::iterator it;

int main()
{
    vector<int> heights = {6,2,5,4,5,5,6,5,2,4,2,1,2,1,4};
    vector<int> first_left_min(heights.size(),-1);
    vector<int> first_right_min(heights.size(),-1);
    stack<int> mystack;

    int max_area = 0;

    #ifdef BRUTE    
        for(it start = heights.begin();start < heights.end();start++)
        {
            for(it end = start+1;end < heights.end();end++)
            {
                int l = *min_element(start,end);
                int b = distance(start,end);

                int area = l*b;
                max_area = max(max_area,area);

            }
        }
    #endif

    #ifndef BRUTE
    /* BUILDING RIGHT ARRAY */
    for(int i=0;i<heights.size();i++)
    {
        if(mystack.empty())
        {
            mystack.push(i);
        }
        else
        {
            if(heights[mystack.top()] < heights[i])
            {
                mystack.push(i);
            }
            else
            {
                while(heights[mystack.top()] > heights[i])
                {
                    first_right_min[mystack.top()] = i;
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
    
    if(!mystack.empty())
        mystack.pop();
    
    /* BUILDING LEFT ARRAY*/
    for(int i=heights.size()-1;i>=0;i--)
    {
        if(mystack.empty())
        {
            mystack.push(i);
        }
        else
        {
            if(heights[mystack.top()] < heights[i])
            {
                mystack.push(i);
            }
            else
            {
                while(heights[mystack.top()] > heights[i])
                {
                    first_left_min[mystack.top()] = i;
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
    #ifdef DEBUG
        cout<<"First Left Minimum array is: \n";
        for(auto i: first_left_min)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    #endif

    #ifdef DEBUG
        cout<<"First Right Minimum array is: \n";
        for(auto i: first_right_min)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    #endif
    for(int i=0;i<heights.size();i++)
    {   
        int start,end,area;
        
        
        (first_left_min[i] == -1)?(start = 0):(start = first_left_min[i] + 1);
        (first_right_min[i] == -1)?(end = heights.size()-1):(end = first_right_min[i] - 1);
    
        

        
        area = heights[i]*(end - start + 1);
        max_area = max(area,max_area);
        #ifdef DEBUG
            cout<<"====================================\n";
            cout<<"For height: "<<heights[i]<<endl;
            cout<<"start is at: "<<start<<endl;
            cout<<"end is at: "<<end<<endl;
            cout<<"area is : "<<area<<endl;
        #endif
    }

    #endif   

    cout<<"Maximum area of rectangle formed by given histogram is: "<<max_area<<endl;
    return 0;

    
}