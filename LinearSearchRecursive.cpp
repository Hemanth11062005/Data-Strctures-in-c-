#include<iostream>
using namespace std;
int LinearSearchRecursive(int arr[], int target, int start, int end){
    if(start>end){
        return -1;
    }
    else if(arr[start]==target){
        return start;
    }
    return LinearSearchRecursive(arr,target,start+1,end);
}
int main(){
    int  arr[100],target,result,i,size;
    cout<<"enter size of array:"<<endl;
    cin>>size;
    cout<<"enter array elements:"<<endl;
    for(i=0;i<size;i++){
        cin>>arr[i];
    }
     cout<<"enter target:"<<endl;
    cin>>target;
    result = LinearSearchRecursive(arr,target,0,size);
    if(result == -1)
    {
        cout<<"element not found"<<endl;
    }
    else{
        cout<<"Element found at index:"<<result;
    }
}