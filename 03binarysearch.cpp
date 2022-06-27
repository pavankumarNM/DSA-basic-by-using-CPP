#include<iostream>
using namespace std;
int binarysearch(int arr[],int element,int size){
    int low=0,high=size-1,mid;
    while (low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==element){
           return mid;
        }
        else if(arr[mid]<element)
        {
            low=mid+1;
        }
        else{
             high=mid-1;
        }
    }
    return -1;
    
}
int main(){
    int arr[]={-2,-1,0,1,2,3,4,5},element=2,size=9,result;
    result=binarysearch( arr,element,size);
    cout<<"the "<<element<<" found at index "<<result;
    return 0;
}