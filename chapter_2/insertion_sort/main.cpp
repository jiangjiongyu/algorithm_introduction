#include <iostream>

using namespace std;

int main()
{
    int a[] = {5,2,4,6,1,3};
    for(unsigned int i = 1;i < sizeof(a)/sizeof(int); ++i)
    {
        int key = a[i];
        int j = i - 1;
        int k = i - 1;
        while (j >= 0)
        {
            if(a[j] < key)
            {
                a[j + 1] = a[j];
                --k;
            }
            j = j - 1;
        }
        a[k+1] = key;
    }
    for(auto b:a)
    {
        cout << b << endl;
    }
    return 0;
}
