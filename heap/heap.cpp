#include<iostream>
#include<vector>

using namespace std;

vector<int> build_heap(vector<int>& );
void upheap(int,vector<int>& );
void insert(int);
void remove(int);
int find_top();

vector<int>* heap_ptr = NULL;

int main()
{
    vector<int> arr = {10,30,50,80,200,25,8};

    for(auto i:arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    vector<int> max_heap (build_heap(arr));
    heap_ptr = &max_heap;

    for(auto i: max_heap)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    insert(35);
    for(auto i: max_heap)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    remove(find_top());
    for(auto i: max_heap)
    {
        cout<<i<<" ";
    }
    cout<<endl;

}
vector<int> build_heap(vector<int>& arr )
{
    vector<int> heap;

    for(int i=0;i<arr.size();i++)
    {
        heap.push_back(arr[i]);
        upheap(i,heap);
    }
    return heap;
}

void upheap(int index_inserted,vector<int>& heap)
{

    int father = index_inserted/2;

    if(father < 0)
    {
        return;
    }

    if(heap[father] < heap[index_inserted])
    {
        swap(heap[father],heap[index_inserted]);
        upheap(father,heap);
    }

}

void insert(int element)
{
    cout<<"Inserted "<<element<<endl;
    (*heap_ptr).push_back(element);
    upheap((*heap_ptr).size()-1,(*heap_ptr));


}
int find_top()
{
    cout<<"The top is: "<<(*heap_ptr)[0]<<endl;
    return 0;
}
int max_index(int left_child,int right_child)
{
    if((*heap_ptr)[left_child] >= (*heap_ptr)[right_child] )
    {
        return left_child;
    }
    return right_child;
}
void down_heap(int father)
{
    int child = (father * 2)+1;
    if(child >= (*heap_ptr).size() || child+1 >= (*heap_ptr).size() )
    {
        return;
    }
    int child_max = max_index(child,child+1);
    swap((*heap_ptr)[child_max],(*heap_ptr)[father]);
    down_heap(child_max);
}
void remove(int index)
{
    cout<<"Topmost element removed\n";
    swap((*heap_ptr)[index],(*heap_ptr)[(*heap_ptr).size()-1]);
    (*heap_ptr).erase((*heap_ptr).end()-1);
    down_heap(0);
}