#include <iostream>
using namespace std;
void printsort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "the element at index : " << i << " is " << arr[i] << endl;
    }
}
void insertionsort(int *arr, int n)
{
    for (int i = 1; i < n ; i++)
    {
        int key = arr[i];

        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            arr[j] = key;
            j--;
        }
        arr[j + 1] = key;
    }
    cout<<"printing after the insertion "<<endl;
}
int main()
{
    int arr[] = {6, 4, 3, 2, 1, 5};
    int size = 6;
    printsort(arr, size);
    insertionsort(arr, 6);
    printsort(arr, size);

    return 0;
}