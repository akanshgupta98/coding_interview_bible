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
    vector<int> distinct( *( max_element(arr.begin(),arr.end()) )+1,0);
    int k = mydata.k;
    int count = 0;

    int left = 0;
    int right;
    int ans = 0;
    for(right = 0;right<arr.size();right++)
    {
        distinct[arr[right]]+= 1;
        
        if(distinct[arr[right]] == 1)
        {
            count++;
        }
        
        if(count > k)
        {
            count--;
            distinct[arr[right]]--;
            right--;
            
            break;
        }
    }
    if(right == arr.size())
    {
        right--;
    }
    
    ans = right - left + 1;
    
    

    for(left = 1;left < arr.size();left++)
    {
        //cout<<"count of: "<<arr[left-1]<<" : "<<distinct[arr[left-1]]<<" unique elements: "<<count<<endl;
        distinct[arr[left-1]]--;
        
        if(distinct[arr[left-1]] == 0)
        {
            count--;
        }
        
        else
        {
            continue;
        }

        while(right < arr.size())
        {
            
            distinct[arr[right]]++;
            
            if(distinct[arr[right]] == 1)
            {
                count++;
            }
            
            if(count > k)
            {
                count--;
                distinct[arr[right]]--;
                right--;
                break;
            }
            
            right++;

        }
        
        if(right == arr.size())
        {
            ans = max(ans,right-left+1);
            break;
        }

        ans = max(ans,right-left+1);

    }
    
    cout<<"Longest sub-array with at most "<<k<<" distinct elements: "<<ans<<endl;
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