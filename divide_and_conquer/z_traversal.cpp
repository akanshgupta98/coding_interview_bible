#include<iostream>

using namespace std;

int get_value(int n,int x,int y);
int main(int argc,char* argv[])
{
    if(argc < 4)
    {
        cout<<"Syntax Error. Expected Syntax<a.out,n,x,y>\n";
        return -1;
    }
    int n = stoi(argv[1]);
    int x = stoi(argv[2]);
    int y = stoi(argv[3]);

    cout<<"Value of ("<<x<<","<<y<<") in a "<<(1<<(n))<<"x"<<(1<<(n))<<" matrix is: "<<get_value(n,x,y)<<endl;
    return 0;
}
int get_value(int n,int x,int y)
{
    #ifdef DEBUG
        cout<<"Value of ("<<x<<","<<y<<") in a "<<(1<<(n))<<"x"<<(1<<(n))<<" matrix "<<endl;
    #endif
    if(n == 0)
    {
        return 1;
    }
    /* checking for x,y lying in I or II */
    if(x < (1<<(n-1)))
    {
        /* checking for I quadrant */
        if(y < (1 << (n-1)))
        {
            return (get_value(n-1,x,y));
        }
        else
        {
            return ( (1<<(2*n-2)) + ( get_value( n-1, x , y-( 1 << (n-1) ) ) ) );
        }

    }

    /* checking for x,y lying in III or IV */
    else
    {
        /* checking for III quadrant */
        if(y < (1 << (n-1)))
        {
            return (  (1<<(2*n-1))+ get_value(n-1,x - (1 << (n-1) ),y));
        }
        else
        {
            return ( (3 * (1 << (2*n-2) ) ) + ( get_value( n-1, x -( 1 << (n-1) ) , y-( 1 << (n-1) ) ) ) );
        }
    }

}