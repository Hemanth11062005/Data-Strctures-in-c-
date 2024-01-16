#include<iostream>
using namespace std;
int LinearSearch(int arr[],int size, int target){
    for(int i=0;i<size;i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[100],i,size,target;
    int result;
    cout<<"enter size of array:"<<endl;
    cin>>size;
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"enter target element:"<<endl;
    cin>>target;
    result = LinearSearch(arr,size,target);
    if(result == -1)
    {
        cout<<"element not found"<<endl;
    }
    else{
        cout<<"Element found at index:"<<result;
    }

}