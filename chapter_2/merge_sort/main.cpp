#include <iostream>

using namespace std;
typedef unsigned int unint;
/*sort[first_po,second_po];sort[second_po+1,end_po]*/
void merge(unint *sort,unint first_po,unint second_po,unint end_po)
{
    //unint f_arry_len = second_po - first_po + 1 + 1;
    //unint s_arry_len = end_po - second_po + 1;
    unint f_arry_len = second_po - first_po + 1;
    unint s_arry_len = end_po - second_po;
    unint* left_arr = new unint[f_arry_len];
    unint* right_arr = new unint[s_arry_len];

    for (unint i = 0;i < f_arry_len; ++i)
    {
        left_arr[i] = sort[first_po + i];
    }
    //left_arr[f_arry_len - 1] = 0xff;

    for (unint i = 0;i < s_arry_len; ++i)
    {
        right_arr[i] = sort[second_po + i + 1];
    }
    //right_arr[s_arry_len - 1] = 0xff;

    unint i = 0;
    unint j = 0;
    for(unint k = first_po;k <= end_po;++k)
    {
        if(left_arr [i] <= right_arr[j])
        {
            sort[k] = left_arr[i];
            ++i;
        }
        else
        {
            sort[k] = right_arr[j];
            ++j;
        }
    }

    free(left_arr);
    left_arr = NULL;
    free(right_arr);
    right_arr = NULL;
    return;
}
void merge_sort(unint *sort, unint first_po, unint end_po)
{
    if(first_po < end_po)
    {
        unint second_po = (first_po + end_po)/2;
        merge_sort(sort,first_po,second_po);
        merge_sort(sort,second_po+1,end_po);
        merge(sort,first_po,second_po,end_po);
    }
    return;
}

int main()
{
    unint sort[] = {5,2,4,7,1,3,2,6};
    merge_sort(sort,0,sizeof(sort)/sizeof(unint) - 1);
    for(auto a : sort)
        cout << a << endl;
    return 0;
}


