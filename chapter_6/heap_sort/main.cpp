#include <iostream>
#include <cstdlib>

using namespace std;

#define ERR_CODE 0x7fffffff

int GetParentIndex(int position, int heapsize)
{
    if(position >= heapsize)
        return ERR_CODE;
    return (position / 2);
}

/*get left point*/
int GetLeftSonIndex(int position, int heapsize)
{
    if(2 * position >= heapsize)
        return ERR_CODE;
    if(position == 0)
        return 1;
    return (2 * position);
}

/*get right point*/
int GetRightSonIndex(int position, int heapsize)
{
    if((2 * position + 1) >= heapsize)
        return ERR_CODE;
    if(position == 0)
        return 2;
    return (2 * position + 1);
}

/*exchange value between two arugments*/
void ExchangeValue(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

/*bulid the max subtree*/
void MaxHeapify(int *Array, int position, int heapsize)
{
    int largest = position;
    int left = GetLeftSonIndex(position, heapsize);
    int right = GetRightSonIndex(position, heapsize);
    if(left <= heapsize - 1
            && *(Array + left) > *(Array + largest) && ERR_CODE != left )
    {
        largest = left;
    }
    if(right <= heapsize - 1
            && *(Array + right) > *(Array + largest) && ERR_CODE != right )
    {
        largest = right;
    }
    if(largest != position)
    {
        ExchangeValue((Array + largest), (Array + position));
        MaxHeapify(Array, largest, heapsize);
    }
    return;
}

void BuildMaxHeapTree(int *Array,int length)
{
    int heapsize = length;
    for(int i = int(length/2 - 1); i >= 0; --i)//from tree bottom to tree top
    {
        MaxHeapify(Array, i, heapsize);
    }
    return;
}

void HeapSort(int *Array,int length)
{
    BuildMaxHeapTree(Array, length);
    int heapsize = length;
    for(int i = length - 1; i > 0; --i)
    {
        ExchangeValue((Array + i), (Array + 0));
        heapsize--;//pick out the ranked elemnt
        BuildMaxHeapTree(Array, heapsize);
    }
}

int main()
{
    int heapArray[] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    HeapSort(heapArray, sizeof(heapArray)/sizeof(int));
    for (auto element : heapArray)
    {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}
