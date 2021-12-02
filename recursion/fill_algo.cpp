#include<iostream>
#include<vector>

using namespace std;


vector<vector<char>> board
{
    {'.' ,  '#'  , '.' ,  '.'   ,'#'},
    {'#' ,  '#'  , '.' ,  '#'   ,'#'},
    {'.' ,  '.'  , '.' ,  '.'   ,'.'},
    {'#' ,  '#'  , '#' ,  '#'   ,'.'},
    
    
};

vector<vector<bool>> visited;

vector<int8_t> dir_x{0,0,-1,1};
vector<int8_t> dir_y{1,-1,0,0};
int max_cell = 0;
int cells = 0;


void fill(int,int);
bool isValid(int,int);
int main()
{
   
    int island = 0;
    int cells = 0;
    
    for(int i=0;i<board.size();i++)
    {
        vector<bool> temp(board[i].size(),false);
        visited.push_back(temp);
    }

    #ifdef DEBUG
        cout<<"Given board is: \n";
        for(auto i: board)
        {
            for(auto j: i)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
        cout<<"===============";
        cout<<"Visited matrix is: \n";
        for(auto i: visited)
        {
            for(auto j: i)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    #endif

    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[i].size();j++)
        {
            ::cells = 0;
            if(isValid(i,j))
            {
                fill(i,j);
                island++;

                max_cell = max(max_cell,::cells);
                
            }
            

        }
    }
    cout<<"Number of islands in this board: "<<island<<endl;
    cout<<"Maximum Number of cells in an island: "<<max_cell<<endl;
    
    return 0;
}

bool isValid(int row,int col)
{
    
    if(row < 0 || col < 0 || col >= board[row].size() || row >= board.size())
    {
        return false;
    }
    
    if(board[row][col] == '#' || visited[row][col])
    {
        return false;
    }
    
    
    return true;
}

void fill(int row,int col)
{
    visited[row][col] = true;
    ::cells++;
    

    for(int i=0;i<4;i++)
    {
        if(isValid(row+dir_x[i],col+dir_y[i]))
        {
            fill(row+dir_x[i],col+dir_y[i]);
        }
    } 
    

}