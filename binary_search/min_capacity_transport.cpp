#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

using namespace std;
class Data
{
    public:
    vector<int> arr;
    int k;
    
    
    Data()
    {
        k = 0;
       
    }
    Data(vector<int> numbers,int start)
    {
        this->k = start;
        
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
    cout<<"value of k: "<<k<<endl;

    
}


Data get_input(char* user_input[]);
vector<int> make_runsum(Data&);

int main(int argc, char* argv[])
{

    if(argc < 3)
    {
        cout<<"Error. Expected Syntax: <object file,array,integer k>\n";
        return -1;
    }

    Data mydata = get_input(argv);

    
    #ifdef DEBUG
        
        mydata.print_data();

    #endif

    vector<int> arr = mydata.arr;
    int k = mydata.k;
    #ifdef BRUTE
    int c = *max_element(arr.begin(),arr.end());
    bool c_not_found = true;
    

    while(c_not_found)
    {
        int i=0;
        for(int trips = 0;trips<k;trips++)
        {
            int sum = 0;
            while(i >=0 && i < arr.size())
            {
                sum += arr[i];
                i++;

                if(sum > c)
                {
                    break;
                }
                
            }
            i--;
            #ifdef DEBUG
                cout<<"sum is: "<<sum<<endl;
            #endif
            if(sum <= c && i == arr.size()-1)
            {
                c_not_found = false;
                break;
            }
            
        }
        
        if(c_not_found)
        {
            c++;
        }

    }
    #endif

    
    int c;
    int start = *max_element(arr.begin(),arr.end());
    int end = accumulate(arr.begin(),arr.end(),1);

    while(start != end)
    {
        bool c_not_found = true;
        c = (start+end)/2;
        #ifdef DEBUG
            cout<<"start is: "<<start<<" end is: "<<end<<" mid is: "<<c<<endl;
        #endif
        int i=0;
        for(int trips = 0;trips<k;trips++)
        {
            int sum = 0;
            while(i >=0 && i < arr.size())
            {
                sum += arr[i];
                i++;

                if(sum > c)
                {
                    break;
                }
                
            }
            i--;
            
            if(sum <= c && i == arr.size()-1)
            {
                c_not_found = false;
                break;
            }
            
        }
        
        if(c_not_found)
        {
            start = c+1;
            
        }
        else
        {
            end = c;
        }

    }
    c = start;

    cout<<"Minimum capacity of my truck to transport all my goods in "<<k<<" rounds is: "<<c<<endl;

    return 0;
}
Data get_input(char* user_input[])
{
    
    int k = stoi(user_input[2]);
    
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
    
    Data d1(nums,k);
    return d1;


}
    

