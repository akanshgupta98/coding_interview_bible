#include<iostream>


using namespace std;
typedef long long ll;
int compute_pow(int base,int exp)
{
    if(exp == 0)
    {
        return 1;
    }
    else if(exp % 2 != 0)
    {
        return(base * compute_pow(base,exp-1));
    }

    return(compute_pow(base*base,exp/2));
}
int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        cout<<"Error. Expected Syntax:<object file,integer (base),integer (power)>\n";
        return -1;
    }
    int base = stoi(argv[1]);
    int exp = stoi(argv[2]);
    int mod = 1000000009;

    int ans = 1;
    ans = compute_pow(base,exp);
    
    cout<<"My ans: "<<ans<<endl;
    

}