#include<iostream>
#include<vector>
#include<chrono>

using namespace std;

int main(int argc,char* argv[])
{
    if(argc < 2)
    {
        cout<<"Error. Expected Syntax:<object file,integer>\n";
        return -1;
    }
    int n = stoi(argv[1]);

    vector<bool> primes(n+1,true);
    primes[0] = false;
    primes[1] = false;
    
    for(int i=2;i<n/2;i++)
    {
        if(!primes[i])
        {
            continue;
        }
        
        for(int j=2;i*j<=n;j++)
        {
            primes[i*j] = false;
        }

    }

    cout<<"Prime numbers till "<<n<<endl;
    for(int i=0;i<primes.size();i++)
    {
        if(primes[i])
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
    return 0;
}