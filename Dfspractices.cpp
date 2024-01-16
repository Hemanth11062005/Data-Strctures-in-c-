#include<iostream>
using namespace std;
void dfs(int);
int a[20][20],n,vi[20];

int main(){
    int i,j;
    cout<<"Enter number of vertices:"<<endl;
    cin>>n;
    for(i=1;i<=n;i++){
        vi[i]=0;
    }
    cout<<"Enter adjacency matrix:"<<endl;
    for(i=1;i<=n;i++){
       for(j=1;j<=n;j++){
        cin>>a[i][j];
       } 
    }
    cout<<"Depth First Traversal"<<endl;
    dfs(4);
}

void dfs(int v){
    int i;
    vi[v]=1;
    cout<<v;
    for(i=1;i<=n;i++){
        if(i!=v && a[v][i]==1 && vi[i]==0){
            dfs(i);
        }
}
}