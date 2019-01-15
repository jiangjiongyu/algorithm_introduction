#include <iostream>

using namespace std;

/*exchange value between two arugments*/
void ExchangeValue(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

/*
 * core part:
 * divide the array into three parts
 * Array[startPosition, EndPosition]
 * first part:Array[startPosition, detachPosition - 1]
 * second part:Array[detachPosition]
 * third part:Array[detachPosition + 1, EndPosition]
 */
int BuildSortArray(int *Array, int startPosition, int EndPosition)
{
    int Refrence = Array[EndPosition];
    int i = startPosition - 1;//get the position behind startPosition
    for(int j = startPosition; j < EndPosition; ++j)//j is the sequential index of the whole array
    {
        if(Array[j] <= Refrence)//encounter the aim move i and exchange position value
        {
            ++i;
            ExchangeValue(Array + i, Array + j);
        }
    }
    ExchangeValue(Array + i + 1, Array + EndPosition);
    return i+1;
}

/*
 * divide the whole array
 * then divide the first part
 * then divide the third part
 * until the sub array only have one element
 */
void QuickSort(int *Array, int startPosition, int EndPosition)
{
    if(startPosition >= EndPosition)
        return;
    int detachPosition = BuildSortArray(Array, startPosition, EndPosition);
    QuickSort(Array, startPosition, detachPosition - 1);
    QuickSort(Array, detachPosition + 1, EndPosition);
}

int main()
{
    int SortArray[] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    QuickSort(SortArray, 0, sizeof(SortArray)/sizeof(int) - 1);
    for(auto c:SortArray)
        cout << c << " " ;
    cout << endl;
    return 0;
}
