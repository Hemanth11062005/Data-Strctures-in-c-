#include<iostream>
using namespace std;
int binarySearchIterative(int arr[],int size, int target){
    int mid;
    int left=0,right=size;
    mid=(left+size)/2;
    while(left<right){
        if(target == arr[mid]){
            return mid;
        }
        else if(target < arr[mid]){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
        return -1;
    }




}
int main()
{
int arr[100],i,size,target;
cout<<"Enter array size:"<<endl;
cin>>size;
cout<<"Enter array elements:"<<endl;
for(int i=0;i<size;i++)
{
cin>>arr[i];
}
cout<<"Enter element to be searched:"<<endl;
cin>>target;
int result=binarySearchIterative(arr,size,target);
if(result!=-1)
{
cout<<"Element is found at index:"<<result+1<<endl;
}
else
{
cout<<"Element not found in the array"<<endl;
}
return 0;
}
