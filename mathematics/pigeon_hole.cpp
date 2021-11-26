#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char* argv[])
{

    if(argc < 2)
    {
        cout<<"Error. Expected Syntax<object file,integer>\n";
        return -1;
    }
    int result = 0;

    int n = stoi(argv[1]);
    vector<int> remainders(n,0);

    long long temp = 0;
    for(int i=1;i<=n;i++)
    {
        temp = (temp*10 + 1) % n;
        if(remainders[temp] != 0){
            int j;
            for(j = 0;j<(i-remainders[temp]);j++ )
            {
                cout<<"1";
            }
            for(int k=j;k<i;k++)
            {
                cout<<"0";
            }
            break;
        }
        
        
        remainders[temp] = i;
    }
    cout<<endl;

    return 0;
}