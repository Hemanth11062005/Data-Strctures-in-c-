#include<iostream>
using namespace std;
int main()
{
    int a[100],i,temp;
    cout<<"Enter array elements:"<<endl;
    for(i=0;i<5;i++)
    {
        cin>>a[i];
    }
    
    for(i=0;i<5;i++)
    {
        int temp=a[i];
        int j=i-1;
        while(j>=0&&a[j]>temp)
        {
        a[j+1]=a[j];
        j--;
        }
        a[j+1]=temp;
    }
    cout<<"\n";
    for(i=0;i<5;i++)
    {
        cout<<a[i]<<"\n";
    }
}