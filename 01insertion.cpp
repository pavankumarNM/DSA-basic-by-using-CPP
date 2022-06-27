#include<iostream>
using namespace std;
void display (int arr[],int u){
    for (int i = 0; i < u; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}
int set(int arr[],int u,int s,int index,int element){
    if (u>s)
    {
        return -1;
    }
    
    for (int i = u-1; i >=index ; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    
}
int main(){
    int arr[20]={0,1,3,4,5},u=5,s=20,element=2,index=2;
    display(arr,u);
    set(arr,5,20,2,2);
    u+=1;
    display(arr,u);
    return 0;
}




