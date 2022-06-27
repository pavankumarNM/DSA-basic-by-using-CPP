#include<iostream>
using namespace std;
void printbubble(int *arr,int n){
    for (int  i = 0; i < n; i++)
    {
        cout<<"the element at index : "<<i <<" is "<<arr[i]<<endl;
    }
    
}
void adaptivebubblesort(int *arr,int n){
    for (int  i = 0; i < n-1; i++)
    {   int exit=1;
      cout<<"the sorting for "<<i+1<<" time "<<endl;
        for (int  j= 0; j < n-1-i; j++)
        {  
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                exit=0;
            }
        }
        if(exit){
            return;
        }
    }
    
}
void normalbubblesort(int *arr,int n){
    for (int  i = 0; i < n-1; i++)
    {  
      cout<<"the sorting for "<<i+1<<" time "<<endl;
        for (int  j= 0; j < n-1-i; j++)
        {  
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                
            }
        }
       
    }
    
}
int main(){
    int arr[]={1,2,3,4,5,6};
    int size=6;
    printbubble(arr,size);//before bubblesort
    //adaptivebubblesort(arr,size); //bubblesorting by adaptive process
    normalbubblesort(arr,size);// bubble sort by normal process
    printbubble(arr,size);//after bubblesort

    return 0;
}