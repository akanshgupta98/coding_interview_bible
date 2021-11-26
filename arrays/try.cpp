#include<iostream>

using  namespace std;

int main()
{
    int inner = 0;
    int outer = 0;
    for(int i=0;i<11;i++)
    {
        outer++;
        
        for(int j=i+1;j<11;j++)
        {
            inner++;
        }
        
    }
    cout<<"outer: "<<outer<<endl<<"inner: "<<inner<<endl;
    return 0;
}