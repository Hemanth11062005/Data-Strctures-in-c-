#include<iostream>
using namespace std;
#define INF 999;
int main()
{
    int v,e=0,i,mc=0;
    cout<<"enter no. vertices";
    cin>>v;
    int a[v][v];
    bool vi[v];
    for(i=1;i<=v;i++)
    {
        vi[i]=false;
    }
    vi[1]=true;
    cout<<"enter adjacency matrix";
    for(i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++)
        {
            cin>>a[i][j];
        }
    }
    while(e<v-1)
    {
        int min=INF;
        int x=0,y=0;
        for(i=1;i<=v;i++)
        {
            if(vi[i])
            {
                for(int j=1;j<=v;j++)
                {
                    if(!vi[j]&&a[i][j]!=0&&min>a[i][j])
                    {
                       min =a[i][j];
                       x=i;y=j;

                    }
                }
            }
        }cout<<x<<"-"<<y<<"-"<<min<<endl;
        vi[y]=true;
        mc+=min;
        e++;    }cout<<mc;
}