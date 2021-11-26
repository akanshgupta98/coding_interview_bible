#include<iostream>
#include<vector>

using namespace std;
class Data
{
    public:
    vector<int> arr;
    int start;
    int end;
    
    Data()
    {
        start = 0;
        end = 0;
    }
    Data(vector<int> numbers,int start,int end)
    {
        this->start = start;
        this->end = end;       
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
    cout<<"Start query: "<<start<<endl;
    cout<<"End query: "<<end<<endl;
}


Data get_input(char* user_input[]);
vector<int> make_runsum(Data&);

int main(int argc, char* argv[])
{

    if(argc < 3)
    {
        cout<<"Error. Expected Syntax: <object file,array,start_query,end_query>\n";
        return -1;
    }

    Data mydata = get_input(argv);
    
    #ifdef DEBUG
        
        mydata.print_data();

    #endif
    
    vector<int> run_sum(make_runsum(mydata));
    
    if( mydata.start < 0 || 
        mydata.end >= mydata.arr.size() )
    {
        cout<<"Invalid Range\n";
        return -1;
    }

    int part_sum = 0;
    
    if(mydata.start == 0)
    {
        part_sum = run_sum[mydata.end];

    }
    else
    {
        part_sum = run_sum[mydata.end] - run_sum[mydata.start-1];
    }
    
    cout<<"Partial sum is: "<<part_sum<<endl;
    

    return 0;

}

Data get_input(char* user_input[])
{
    
    int start = stoi(user_input[2]);
    int end = stoi(user_input[3]);
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
    
    Data d1(nums,start,end);
    return d1;


}

vector<int> make_runsum(Data& data_obj)
{
    vector<int> run_sum;
    int sum = 0;

    for(auto i : data_obj.arr){
        sum += i;
        run_sum.push_back(sum);
    }
    return run_sum;

}