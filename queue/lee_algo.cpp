#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<int> dir_x({0,0,-1,1});
vector<int> dir_y({1,-1,0,0});
int max_rows = 0;
int max_col = 0;
vector<vector<int>>* mat_ptr = NULL;
vector<vector<bool>>* vis_ptr = NULL;
bool isValid(int x,int y);

int main()
{
    vector<vector<int>> matrix
    {
        {1,1,1,1,1,1,1,1,0},
        {1,1,1,0,1,0,0,1,1},
        {0,0,1,1,0,0,0,0,1},
        {0,1,1,0,0,1,1,0,1},
        {0,1,0,0,0,0,0,0,1},
        {1,1,0,0,1,1,1,1,1},
        {0,1,1,1,1,0,1,1,1},
        {0,1,0,0,1,0,1,0,0},
        {0,1,1,0,1,0,1,1,0}
    };
    mat_ptr = &matrix;
    ::max_rows = matrix.size();
    ::max_col = matrix[0].size();

    vector<vector<bool>> visited;

    for(int i=0;i<matrix.size();i++)
    {
        vector<bool> temp(matrix[i].size(),false);
        visited.push_back(temp);

    }
    vis_ptr = &visited;

    int source_x = 6;
    int source_y = 5;
    int dest_x = 2;
    int dest_y = 3;
    int cost = 0;

    queue<vector<int>> myqueue;
    vector<int> temp = {source_x,source_y,cost};
    myqueue.push(temp);
    visited[source_x][source_y] = true;

    while(!myqueue.empty())
    {
        vector<int> co_ordinates(myqueue.front());
        
        if(co_ordinates[0] == dest_x && co_ordinates[1] == dest_y)
        {
            cost = co_ordinates[2];
            break;
        }
        myqueue.pop();

        for(int i=0;i<4;i++)
        {
            
            if(isValid(co_ordinates[0] + dir_x[i],co_ordinates[1] + dir_y[i]))
            {
                vector<int> new_cor = {co_ordinates[0] + dir_x[i],co_ordinates[1] + dir_y[i],co_ordinates[2]+1};
                myqueue.push(new_cor);
                visited[new_cor[0]][new_cor[1]] = true;
            }
        }

    }
    cout<<"Path from source to destination in minimum cost is: "<<cost<<endl;
    return 0;
}

bool isValid(int x,int y)
{
    if(x < 0 || x >= max_rows || y < 0 || y >= max_col)
    {
        return false;
    }
    if((*mat_ptr)[x][y] == 0 || (*vis_ptr)[x][y] )
    {
        return false;
    }
    return true;
}