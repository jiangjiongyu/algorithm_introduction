#include <iostream>

using namespace std;

typedef struct
{
    size_t low;
    size_t high;
    int sum;
}SUB_ARR;
SUB_ARR find_max_crossing_subarray(int* array,size_t low,size_t mid,size_t high)
{
    size_t max_left = 0;
    int left_sum = 0xf0ffffff;
    int sum = 0;
    for(int i = (int)mid; i >= (int)low; --i)
    {
       sum = sum + array[i];
       if(sum > left_sum)
       {
           left_sum = sum;
           max_left = i;
       }
    }

    size_t max_right = 0;
    int right_sum = 0xf0ffffff;
    sum = 0;
    for(size_t i = mid + 1; i <= high; ++i)
    {
        sum = sum + array[i];
        if(sum > right_sum)
        {
            right_sum = sum;
            max_right = i;
        }
    }

    SUB_ARR RetVal;
    RetVal.low = max_left;
    RetVal.high = max_right;
    RetVal.sum = left_sum + right_sum;
    return RetVal;
}

SUB_ARR find_max_subarray(int* array, size_t low, size_t high)
{
    if(low == high)
    {
        SUB_ARR RetVal;
        RetVal.low = low;
        RetVal.high = high;
        RetVal.sum = array[low];
        return RetVal;
    }
    else
    {
        size_t mid = (low + high) / 2;
        SUB_ARR left_return = find_max_subarray(array, low, mid);
        SUB_ARR right_return = find_max_subarray(array, mid + 1, high);
        SUB_ARR mid_return = find_max_crossing_subarray(array, low, mid, high);
        if((left_return.sum >= right_return.sum) && (left_return.sum >= mid_return.sum))
        {
            return left_return;
        }
        else if((right_return.sum >= left_return.sum) && (right_return.sum >= mid_return.sum))
        {
            return right_return;
        }
        else
        {
            return mid_return;
        }

    }
}
int main()
{
    int array[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    SUB_ARR RetVal = find_max_subarray(array, 0, sizeof(array)/sizeof(int) - 1);
    for(size_t i = RetVal.low;i <= RetVal.high; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}
