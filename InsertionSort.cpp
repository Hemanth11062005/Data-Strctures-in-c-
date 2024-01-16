#include<iostream>
using namespace std;
int main(){
    int a[100],i,j,n;
    cout<<"Enter array size:"<<endl;
    cin>>n;
    cout<<"Enter array elements:"<<endl;
    for(i = 0 ; i < n; i++){
        cin>>a[i];
    }
    for(i=1;i<n;i++){
        int temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp){
            swap(a[j+1],a[j]);
            j--;
        }
        a[j+1]=temp;
    }
    //sorted array
    for(i=0;i<n;i++){
        cout<<a[i]<<"\t";
    }

}