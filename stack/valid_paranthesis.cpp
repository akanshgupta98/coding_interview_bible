#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool isValid(stack<char>& mystack , string paran);

int main()
{
    string paran = "{(})";
    stack<char> mystack;
    
    ( isValid(mystack,paran) ) ? (cout<<"The given expression is: "<<paran<<" Valid\n"):(cout<<"The given expression is: "<<paran<<" Invalid\n");
    
    return 0;
}
bool isValid(stack<char>& mystack , string paran)
{

    for(auto i: paran)
    {
        #ifdef DEBUG
            cout<<i<<" ";
        #endif
        
        switch (i)
        {
            
            case '{':
                
                mystack.push(i);
                break;
            
            case '(':
                
                mystack.push(i);
                break;
            
            case '[':
                
                mystack.push(i);
                break;
            
            case '}':
                
                if(mystack.top() == '{')
                {
                    mystack.pop();
                }
                else
                {
                    return false;
                }
                break;
            
            case ')':
                
                if(mystack.top() == '(')
                {
                    mystack.pop();
                }
                else
                {
                    return false;
                }
                break;
            
            case ']':
                
                if(mystack.top() == '[')
                {
                    mystack.pop();
                }
                else
                {
                    return false;
                }
                break;
            
        }
    
    }

    if(mystack.empty())
        return true;
    
    return false;
}