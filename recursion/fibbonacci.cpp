#include<iostream>

using namespace std;

int compute_fibb(int);
int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        cout<<"Error. Expected Syntax<a.out,integer>\n";
        return -1;
    }

    int n = stoi(argv[1]);

    cout<<n<<"th Fibbonacci is: "<<compute_fibb(n)<<endl;

    return 0;
}
int compute_fibb(int n)
{
    
    #ifdef DEBUG
        cout<<"n is: "<<n<<endl;
    #endif
    
    if(n <= 1)
    {
        return n;
    }
    
    return (compute_fibb(n-1) + compute_fibb(n-2));
}