#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Data
{
    public:
    vector<int> arr;
    
    
    // Data()
    // {
    //     start = 0;
    //     end = 0;
    // }
    Data(vector<int> numbers)
    {
   
        arr = numbers;
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
    // cout<<"Start query: "<<start<<endl;
    // cout<<"End query: "<<end<<endl;
}


Data get_input(char* user_input[]);

int main(int argc, char* argv[])
{

    if(argc < 2)
    {
        cout<<"Error. Expected Syntax: <object file,array>\n";
        return -1;
    }

    Data mydata = get_input(argv);
    #ifdef DEBUG
        
        mydata.print_data();

    #endif
    vector<int> arr = mydata.arr;
    
    int result = 0;
    int max_result = 0;
    for(int start = 0;start < arr.size();start++)
    {
        int max_ele = arr[start];
        int min_ele = arr[start];
        vector<bool> distinct( *( max_element(arr.begin(),arr.end()) )+1,false);
        result = 0;

        for(int end = start;end < arr.size();end++)
        {
            max_ele = max(max_ele,arr[end]);
            min_ele = min(min_ele,arr[end]);
            if(distinct[arr[end]])
            {
                break;
            }
            else
            {
                distinct[arr[end]] = true;
            }

            if(max_ele - min_ele == end - start)
            {
                result = end - start+1;
            }
            
        
        }
        
        if(max_result < result)
        {
            max_result = result;
        }

    }
    cout<<"Length of longest consecutive numbers sub-array is: "<<max_result<<endl;

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
    
    Data d1(nums);
    return d1;


}