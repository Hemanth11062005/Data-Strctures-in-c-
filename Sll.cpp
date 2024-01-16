#include<iostream>
using namespace std;
int binarySearchRecursive(int arr[],int left,int right,int target)
{
	//if(left<=right)
		int mid=(left+right)/2;
	if(arr[mid]==target)
		return mid;
	else if(arr[mid]<target)
		return binarySearchRecursive(arr,mid+1,right,target);
	else
		return binarySearchRecursive(arr,left,mid-1,target);
    return -1;
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
int result=binarySearchRecursive(arr,0,size,target);
if(result!=-1)
	cout<<"Element found"<<endl;
else
	cout<<"Element is not found"<<endl;
return 0;
}
