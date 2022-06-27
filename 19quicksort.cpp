#include <iostream>
using namespace std;
void printsort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "the element at index : " << i << " is " << arr[i] << endl;
    }
}
int partion(int *arr, int low, int high)
{    
    int i=low+1;
    int pivot = arr[low];
    int temp;
    int j = high;
    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;
    return j;
}
void quicksort(int *arr, int low, int high)
{
    int partionindex;
    if (low < high)
    {

        partionindex = partion(arr, low, high);
        quicksort(arr, low, partionindex - 1);
        quicksort(arr, partionindex + 1, high);
    }
}
int main()
{
    int arr[] = {6, 4, 3, 2, 1, 5};
    int n = 6;
    printsort(arr, n);
    quicksort(arr, 0, n - 1);
    cout<<endl;
    printsort(arr, n);

    return 0;
}