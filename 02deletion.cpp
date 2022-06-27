#include <iostream>
using namespace std;
void display(int arr[], int u)
{
    for (int i = 0; i < u; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int del(int arr[], int u, int index)
{
    if (index > u)
    {
        return -1;
    }

    for (int i = index; i < u; i++)
    {
        arr[i] = arr[i + 1];
    }
}
int main()
{
    int arr[20] = {0, 1, 3, 4, 5}, u = 5, s = 20, index = 2;
    display(arr, u);
    del(arr, 5, 2);
    u -= 1;
    display(arr, u);
    return 0;
}
