#include <iostream>
using namespace std;
void printsort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "the element at index : " << i << " is " << arr[i] << endl;
    }
}
void selectionsort(int *arr, int n)
{
    int indexofmin, temp;
    cout << "Running selection sort......" << endl;
    for (int i = 0; i < n-1 ; i++)
    {
         indexofmin = i;
        for (int j = i + 1; j < n; j++)
        {
           
            if (arr[j] < arr[indexofmin])
            {
               indexofmin=j;
            }
        }
        temp = arr[indexofmin];
       arr[indexofmin]=arr[i];
        arr[i] = temp;
    }
}
int main()
{
    int arr[] = {6, 4, 3, 2, 1, 5};
    int size = 6;
    printsort(arr, size);
    selectionsort(arr, size);
    printsort(arr, size);

    return 0;
}