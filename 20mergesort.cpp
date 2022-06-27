#include <iostream>
using namespace std;
#include <iostream>
using namespace std;
void printsort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "the element at index : " << i << " is " << arr[i] << endl;
    }
}
void mergesort(int *arr, int mid, int low, int high)
{
    int i = low;
    int k = low;
    int j = mid + 1;
    int B[100];
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            B[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            B[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i<=mid)
    {
        B[k]=arr[i];
        i++;k++;
    }
    while (j<=high)
    {
        B[k]=arr[j];
        j++;k++;
    }
    
    
    for (int  i = low; i <= high; i++)
    {
        arr[i]=B[i];
    }
    

}
void MS(int *arr, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        MS(arr, low, mid);  
        MS(arr, mid + 1, high);
        mergesort(arr, mid, low, high);
    }
}
int main()
{
    int arr[] = {6, 4, 3, 2, 1, 5};
    int n = 6;
    printsort(arr, n);
    MS(arr, 0, 6);
    cout << endl;
    printsort(arr, n);

    return 0;
}