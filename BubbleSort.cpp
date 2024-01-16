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
    //sorting array
    for(i=0;i<n-1;i++){
        for(j=0;j<n;j++){
            if(a[j+1]<a[j]){
            int temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            }
        }
    }
    //sorted array
    for(i=0;i<n;i++){
        cout<<a[i]<<"\t";
    }

}