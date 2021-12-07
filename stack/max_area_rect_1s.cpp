#include<iostream>
#include<vector>
#include<stack>

using namespace std;
#ifdef BRUTE
vector<vector<int>> buildColSumMatrix(vector<vector<int>>& matrix);
int max_consecutive_ones(vector<int>& arr);
int main()
{
    vector<vector<int>> matrix
    {
        {1,1,0,1,1,0,1},
        {1,1,1,0,1,1,1},
        {1,1,1,1,1,1,1},
        {0,1,1,1,1,0,1}
    };

    cout<<"Given Matrix is: \n";
    for(auto i: matrix)
    {
        for(auto j: i)
        {
            cout<<j<<" ";
        }
        cout<<endl;

    }

    vector<vector<int>>col_sum(buildColSumMatrix(matrix));

    int max_area = 0;

    for(int r1 = 1;r1 < matrix.size();r1++)
    {
        for(int r2 = r1;r2 < matrix.size();r2++)
        {
            #ifdef DEBUG
                cout<<"R1: "<<r1<<endl;
                cout<<"R2: "<<r2<<endl;
            #endif

            vector<int> temp;

            for(int c = 0; c< matrix[r1].size();c++)
            {
                int temp_sum = col_sum[r2][c] - col_sum[r1-1][c];
                
                #ifdef DEBUG
                    cout<<"C: "<<c<<" ";
                    cout<<"TEMP SUM is: "<<temp_sum<<endl;
                    
                #endif
                (r2 - r1 + 1 == temp_sum)?(temp.push_back(1)):(temp.push_back(0));

                
            }
            #ifdef DEBUG
                    
                cout<<"TEMPORARY Array is: "<<endl;
                for(auto i: temp)
                {
                    cout<<i<<" ";
                }
                cout<<endl;
                
            #endif

            int breadth = max_consecutive_ones(temp);
            int length = r2 - r1 + 1;
            int area = length * breadth;

            max_area = max(max_area,area);

            #ifdef DEBUG
                
                cout<<"Length: "<<length<<endl;
                cout<<"Breadth: "<<breadth<<endl;
                cout<<"Area: "<<area<<endl;
            #endif
            
        }
    }

    cout<<"Maximum area of rectangle full of 1s is: "<<max_area<<endl;

    return 0;
}

vector<vector<int>> buildColSumMatrix(vector<vector<int>>& matrix)
{
    vector<vector<int>> col_sum;

    for(int i=0;i<matrix.size();i++)
    {
        vector<int> temp = matrix[i];
        col_sum.push_back( temp);
    }

    for(int i=1;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[i].size();j++)
        {
            col_sum[i][j] = col_sum[i-1][j] + matrix[i][j];
        }
        
    }

    
    return col_sum;

}

int max_consecutive_ones(vector<int>& arr)
{
    int ans = 0;
    int max_ans = 0;

    for(int i=0;i<arr.size();i++)
    {
        (arr[i])?(ans++):(ans = 0);
        max_ans = max(max_ans,ans);

    }
    return max_ans;
}
#endif

/*
====================================================================================================
GLOBAL FUNCTIONS
====================================================================================================
***************************************************************************************************
@name 
buildHeightsMatrix

@brief
Builds an additional matrix which keeps a track of highest continous 1s which means 
the heights of towers obtained at that particular row. 

@params
matrix: it takes the given matrix as argument which if of type vector<vector<int>>
***************************************************************************************************

***************************************************************************************************
@name
buildFirstMinimum

@brief
This is used to create a vector which keeps track of first minimum element in the 
direction as it is asked to do. 
Execution is different based for which direction we want to get first minimum element. 

@params
direction:  it is of type string which tells what direction i.e(LEFT or RIGHT), we want 
            to build first minimum array element. 

heights: It is an array which contains the height of towers in a particular row.
*************************************************************************************************

*************************************************************************************************
@name 
maxAreaHistogram

@brief
This function calculates the maximum rectangular area that we can make for a given histogram.

@params
heights: this defines the histogram. 
*************************************************************************************************

==================================================================================================
*/

#ifndef BRUTE

vector<vector<int>> buildHeightsMatrix(vector<vector<int>>& matrix);
vector<int> buildFirstMinimum(string direction,vector<int>& heights);
int maxAreaHistogram(vector<int>& heights);
int main()
{
    vector<vector<int>> matrix
    {
        {1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1},
        {0,1,1,1,1,0,1}
    };

    vector<vector<int>> max_heights_row(buildHeightsMatrix(matrix));

    #ifdef DEBUG
        cout<<"Heights Matrix is: \n";
        for(auto i: max_heights_row)
        {
            for(auto j: i)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    #endif
    int max_area = 0;
    for(int r = 0;r < matrix.size();r++)
    {
        vector<int> heights(max_heights_row[r]);
        int area = maxAreaHistogram(heights);
        max_area = max(max_area,area);

    }

    cout<<"Maximum area of rectangle full of 1s is: "<<max_area<<endl;
    
    return 0;
}

vector<vector<int>> buildHeightsMatrix(vector<vector<int>>& matrix)
{
    vector<vector<int>> height_matrix(matrix);
    
    for(int r = 1;r < matrix.size();r++)
    {
        for(int c = 0;c < matrix[r].size();c++)
        {
            height_matrix[r][c] = (matrix[r][c]) ? (height_matrix[r-1][c]+matrix[r][c]) : (0);
            
        }
        
    }

    return height_matrix;
}

int maxAreaHistogram(vector<int>& heights)
{
    vector<int> first_min_left(buildFirstMinimum("LEFT",heights));
    vector<int> first_min_right(buildFirstMinimum("RIGHT",heights));

    int start,end,area;
    int max_area = 0 ;

    for(int i=0; i< heights.size();i++)
    {
        start = (first_min_left[i] == -1) ? (0):(first_min_left[i]+1);
        end = (first_min_right[i] == -1) ? (heights.size()-1):(first_min_right[i]-1);

        area = heights[i] * (end - start + 1);

        #ifdef DEBUG
            cout<<"============================\n";
            cout<<"height: "<<heights[i]<<endl;
            cout<<"start at: "<<start<<endl;
            cout<<"end at: "<<end<<endl;
            cout<<"area: "<<area<<endl;
        #endif
        max_area = max(max_area,area);


    }

    return max_area;

}

vector<int> buildFirstMinimum(string direction,vector<int>& heights)
{
    stack<int> mystack;
    vector<int> arr(heights.size(),-1);

    for(
            int i = (direction == "LEFT")?(heights.size()-1):(0);
            (direction == "LEFT")?(i >= 0):(i < heights.size()) ;
            (direction == "LEFT")?(i--):(i++) 
        )
    
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
                    arr[mystack.top()] = i;
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
        cout<<direction<<" minimum array is: "<<endl;
        for(auto i: arr)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    #endif

    return arr;


}

#endif