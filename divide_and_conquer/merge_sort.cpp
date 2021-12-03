#include<iostream>
#include<vector>

using namespace std;

typedef vector<int>::iterator it;
vector<int>* sorted_arr;
vector<int>* arr;
void merge_sort(it ,it);
void merge_arr(it ,it,it);
int main()
{
    arr = new vector<int> ({10,2,11,3,7,5,4,1,9,-7,19});
    sorted_arr = new vector<int>((*arr).size(),0);
    
    
    cout<<"Original array is: \n";
    for(auto i: *arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    
    #ifdef DEBUG
        cout<<"Extra array is: \n";
        for(auto i : *sorted_arr)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    #endif
    
    merge_sort((*arr).begin(),(*arr).end()-1);
    
    cout<<"Sorted array is: \n";
    for(auto i: (*arr))
    {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}

void merge_sort(it start,it end)
{
    if(start < end)
    {
        it mid = start + distance(start,end)/2;
        /* LEFT */
        merge_sort(start,mid);
        /* RIGHT */
        merge_sort(mid+1,end);
        /* MERGE TWO SUB-ARRAYS  */
        merge_arr(start,mid,end);
    }

}

void merge_arr(it start,it mid, it end)
{
    
    /* LOGIC OF TWO SUB-ARRAYS INDEPENDENTLY SORTED. JUST COMBINING THEM INTO ONE */
    #ifdef DEBUG
        cout<<"start: "<<*start<<" mid: "<<*mid<<" end: "<<*end<<endl;
    #endif
    
    int sorted_trav = 0;
    it left_trav = start;
    it right_trav = mid+1;

    while(left_trav <= mid && right_trav <= end)
    {
        if(*left_trav < *right_trav)
        {
            (*sorted_arr)[sorted_trav++] = *left_trav;
            left_trav++;
        }
        else
        {
            (*sorted_arr)[sorted_trav++] = *right_trav;
            right_trav++;
        }

    }
    
    while(left_trav <= mid)
    {
        (*sorted_arr)[sorted_trav++] = *left_trav;
        left_trav++;
    }
    
    while(right_trav <=end)
    {
        (*sorted_arr)[sorted_trav++] = *right_trav;
        right_trav++;
    }

    #ifdef DEBUG
        cout<<"Extra array is: \n";
        for(auto i : *sorted_arr)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    #endif
    
    /* COPY THE TEMP ELEMENTS INTO ORIGINAL */
    int n = distance(start,end);
    
    for(int i=0;i<=n;i++)
    {
        *start = (*sorted_arr)[i];
        start++;
    }
    
    #ifdef DEBUG
        cout<<"Original array is: \n";
        for(auto i : *arr)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    #endif
   
}