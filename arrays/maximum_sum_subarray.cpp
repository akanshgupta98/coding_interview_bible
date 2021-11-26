#include<iostream>
#include<vector>

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
    
    
    #ifdef GREEDY
        int max_sum =0;
        int run_sum = 0;
        for(int i=0;i<mydata.arr.size();i++)
        {
            run_sum += mydata.arr[i];
            if(run_sum < 0)
            {
                run_sum = 0;

            }
            if(max_sum < run_sum)
            {
                max_sum = run_sum;
            }
        }
    #endif

    vector<int> run_sum;
    int sum = 0;

    for(auto i: mydata.arr)
    {
        sum += i;
        run_sum.push_back(sum);
    }

    int min_s = 0;
    int max_sum = 0;
    for(int i=0;i<run_sum.size();i++)
    {
        if(max_sum < (run_sum[i] - min_s))
        {
            max_sum = run_sum[i]-min_s;
        }
        if(min_s > run_sum[i])
        {
            min_s = run_sum[i];
        }
    }
    
    cout<<"Maximum sub-array sum is: "<<max_sum<<endl;

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