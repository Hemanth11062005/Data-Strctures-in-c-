#include<iostream>
using namespace std;
int binarySearchRecursive(int arr[],int target,int left,int right){
    int mid =(left+right)/2;
    if(left>right){
        return -1;
    }
    else if(arr[mid]==target){
        return mid;
    }
    else if(target>arr[mid]){
        return binarySearchRecursive(arr,target,mid+1,right);
    }
    else{
        return binarySearchRecursive(arr,target,left,mid-1);
    }
}
int main()
{
int arr[100],size,target;
cout<<"Enter array size:"<<endl;
cin>>size;
cout<<"Enter array elements:"<<endl;
for(int i=0;i<size;i++)
{
cin>>arr[i];
}
cout<<"Enter element to be searched:"<<endl;
cin>>target;
int result=binarySearchRecursive(arr,target,0,size);
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
