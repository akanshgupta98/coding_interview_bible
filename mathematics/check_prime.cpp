#include<iostream>
#include<cmath>
#include <chrono>

using namespace std::chrono;

using namespace std;

bool prime_brute(const int&);
bool prime_optimized(const int&);

int main(int argc,char* argv[])
{
    if(argc < 2)
    {
        cout<<"Syntax Error. Expected:(<object file,int n>\n";
        return -1;
    }
    int num = stoi(argv[1]);
    auto start = high_resolution_clock::now();
    cout<<prime_brute(num)<<endl;
    auto stop = high_resolution_clock::now();
    auto duration_brute = duration_cast<microseconds>(stop - start);
    start = high_resolution_clock::now();
    cout<<prime_optimized(num)<<endl;
    stop = high_resolution_clock::now();
    auto duration_optimized = duration_cast<microseconds>(stop - start);

    cout<<"Runtime Brute: "<<duration_brute.count()<<"ms\n";
    cout<<"Runtime Optimized: "<<duration_optimized.count()<<"ms\n";

    
    return 0;
}
bool prime_brute(const int& num)
{
    for(int i=2;i<num;i++)
    {
        if( (num % i) == 0)
        {
            return false;
        }
    }
    return true;
}

bool prime_optimized(const int& num)
{
    for(int i=2;i<sqrt(num);i++)
    {
        if( (num % i) == 0)
        {
            return false;
        }
    }
    return true;
}