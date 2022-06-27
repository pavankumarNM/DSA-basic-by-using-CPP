#include <iostream>
#include <stdlib.h>
#include <limits.h>
using namespace std;
void printsort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "the element at index : " << i << " is " << arr[i] << endl;
    }
    cout << endl;
}
int maxi(int *arr, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    return max;
}
void countsort(int *arr, int n)
{

    int max = maxi(arr, n);
    int *count = (int *)malloc((max + 1) * sizeof(int));
    for (int i = 0; i < max; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i <= max; i++)
    {
        count[arr[i]] = count[arr[i]] + 1;
    }
    int i = 0;
    int j = 0;
    while (i <= max)
    {
        if (count[i] > 0)
        {
            arr[j] = i;
            j++;
            count[i]--;
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    int max;
    int arr[] = {6, 4, 3, 1, 1, 5};
    int size = 6;
    printsort(arr, size);
    countsort(arr, size);
    printsort(arr, size);

    return 0;
}