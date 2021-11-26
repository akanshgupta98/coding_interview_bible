#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        cout<<"Syntax Error. Expected:(<object file,int n>\n";
        return -1;
    }

    vector<int> base;
    vector<int> exp;

    int d = 2;
    int num = stoi(argv[1]);
    int temp = num;
    
    while(num >1 && d < (sqrt(num)+1))
    {
        int exp_count = 0;
        while(num % d == 0)
        {

            num /= d;
            exp_count++;


        }
        if(exp_count > 0)
        {
            base.push_back(d);
            exp.push_back(exp_count);

        }
        d++;

    }

    cout<<temp<<" = ";
    for(int i=0;i<base.size();i++)
    {

        int j = i;
        while(exp[j] != 0)
        {
            cout<<base[i]<<".";
            exp[j]--;
        }

    }
    if(num != 1)
    {
        cout<<num;
    }
    cout<<endl;

    return 0;
}