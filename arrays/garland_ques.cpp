#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Data
{
    public:
    vector<int> arr;
    int k;
    
    
    // Data()
    // {
    //     start = 0;
    //     end = 0;
    // }
    Data(vector<int> numbers,int k)
    {
   
        arr = numbers;
        this->k = k;
    }
    void print_data();

};

void Data:: print_data()
{
    cout<<"user data extracted is\n";
    cout<<"Array entered is: ";
    for(auto i: arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"K is: "<<k<<endl;
    // cout<<"Start query: "<<start<<endl;
    // cout<<"End query: "<<end<<endl;
}


Data get_input(char* user_input[]);

int main(int argc, char* argv[])
{

    if(argc < 3)
    {
        cout<<"Error. Expected Syntax: <object file,array,integer: (k)>\n";
        return -1;
    }

    Data mydata = get_input(argv);
    #ifdef DEBUG
        
        mydata.print_data();

    #endif
    vector<int> arr = mydata.arr;
    int k = mydata.k;
    
    int min_moves = 1000000000;
    int one_count = 0;
    int total_one = 0;

    for(int i=0;i<arr.size();i++)
    {
        if(arr[i] == 1)
        {
            total_one++;
        }
    }
    int r = i%k;
    for(int i=0;i<arr.size();i++)
    {
     
        int moves = one_count;  
        
        int encounterd_one = 0;

        if(arr[i] != 1)
        {
            moves++;
            
        }
        else
        {
            one_count++;
            total_one --;
        }
        cout<<"total count: "<<total_one<<" ";
        
        
        for(int j=i+k;j<arr.size();j+= k)
        {
            
            /* COMPLEXITY OF N. TOTAL COMPLEXITY WITH THIS O(N2). CHANGE FOR LOOP
            TO for(int j=i+1;j<arr.size();j++)*/
            #ifdef COMPL_O_N
                if(j % k == i % k){
                    if(arr[j] != 1)
                    {
                        moves++;
                    }
                }
                else
                {
                    if(arr[j] != 0)
                    {
                        moves++;
                    }
                }
            #endif
            /* COMPLEXITY OF LOG n. TOTAL COMPLEXITY WITH THIS O(nlogn)
            NOT SURE OF TIME COMPLEXITY. I THINK THIS IS ASO LINEAR. SO NO IMPROVEMENT */
            if(arr[j] != 1)
            {
                moves++;
                
            }
            else
                encounterd_one++;
        }
        moves += (total_one - encounterd_one);
        cout<<"If start is: "<<i<<" then moves required are: "<<moves<<endl;
        if(min_moves > moves)
        {
            min_moves = moves;
        }
       
    }
    cout<<"Minimum possible moves to make "<<k<<" garland is: "<<min_moves<<endl;
    return 0;
}
Data get_input(char* user_input[])
{
    
    
    int temp = 0;
    bool is_negative = false;
    vector<int> nums;
    for(int i=0;user_input[1][i] != '\0';i++)
    {
        if(user_input[1][i] == '['){
            continue;
        }
        
        if(user_input[1][i] >= '0' && user_input[1][i] <= '9')
        {
            temp = (temp*10) + (user_input[1][i] - '0');
        }
        
        if(user_input[1][i] == ',')
        {
            if(is_negative)
            {
                temp = -1 * temp;    
            }
            nums.push_back(temp);
            temp = 0;
            is_negative = false;
        }
        
        if(user_input[1][i] == '-')
        {
            is_negative = true;
            continue;
        }

        if(user_input[1][i] == ']')
        {
            if(is_negative)
            {
                temp = -1 * temp;    
            }
            nums.push_back(temp);
        }
    
    }
    int k = stoi(user_input[2]);
    Data d1(nums,k);
    return d1;


}