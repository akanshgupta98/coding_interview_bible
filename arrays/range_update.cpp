#include<iostream>
#include<vector>

using namespace std;
class Data
{
    public:
    vector<int> arr;
    vector<vector<int>> queries;
    
    
    Data(vector<int> numbers,vector<vector<int>> q)
    {
        arr = numbers;
        queries = q;
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
    cout<<"Queries entered are: ";
    
    for(auto i: queries)
    {
        for(auto j: i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    
}


Data get_input(char* user_input[]);
int main(int argc, char* argv[])
{

    if(argc < 3)
    {
        cout<<"Error. Expected Syntax: <object file,array,queries>\n";
        return -1;
    }

    Data mydata = get_input(argv);
    #ifdef DEBUG
        mydata.print_data();
    #endif

    vector<int> updates(mydata.arr.size(),0);
    vector<int> run_sum;

    for(auto i: mydata.queries)
    {
        int start = i[0];
        int end = i[1];
        int val = i[2];

        updates[start] += val;
        updates[end+1] -= val;

    }

    int sum = 0;
    for(auto i: updates)
    {
        sum+= i;
        run_sum.push_back(sum);
    }

    for(int i=0;i<mydata.arr.size();i++)
    {
        mydata.arr[i] += run_sum[i];
    }

    cout<<"Updated Array: \n";
    for(auto i: mydata.arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;



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

    vector<vector<int>> q;
    vector<int> temp_arr;
    temp = 0;
    is_negative = false;
    for(int i=0;user_input[2][i] != '\0';i++)
    {
        if(user_input[2][i] == '['){
            continue;
        }
        
        if(user_input[2][i] >= '0' && user_input[2][i] <= '9')
        {
            temp = (temp*10) + (user_input[2][i] - '0');
        }
        
        if(user_input[2][i] == ',')
        {
            if(is_negative)
            {
                temp = -1 * temp;    
            }
            temp_arr.push_back(temp);
            temp = 0;
            is_negative = false;
        }
        
        if(user_input[2][i] == '-')
        {
            is_negative = true;
            continue;
        }

        if(user_input[2][i] == ']')
        {
            if(temp_arr.size() == 0)
            {
                continue;
            }

            if(temp != 0){
                
                if(is_negative)
                {
                    temp = -1 * temp;    
                }
                temp_arr.push_back(temp);
                temp = 0;
                is_negative = false;
            
            }
            
            
            q.push_back(temp_arr);
            temp_arr.clear();
            
            is_negative = false;
            i++;
        }
    
    }

    
    Data d1(nums,q);
    return d1;


}