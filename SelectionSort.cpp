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
for(i=0;i<n-1;i++){
    int min=i;
    for(j=i+1;j<n;j++){
        if(a[j]<a[min]){
            swap(a[min],a[j]);
        }
    }
}
  //sorted array
    for(i=0;i<n;i++){
        cout<<a[i]<<"\t";
    }

}