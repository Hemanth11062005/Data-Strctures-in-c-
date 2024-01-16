#include<iostream>
using namespace std;
void bfs(int);
int count = 0;
int n, a[20][20],i,j,q[10];
int vi[10];
int f=0,r=0;
void enqueue(int x)
{
if(f==0 && r==0){
f=1;
r=1;}
else
{
r++;
}
q[r]=x;
}
int dequeue()
{
if(f>r)
	return -1;
else
{
int val = q[f];
f++;
return val;
}
}
int main()
{
cout<<"\nEnter the number of vertices:";
cin>>n;
for(i=1;i<=n;i++)
	vi[i] =0;
	cout<<"\nEnter the adajacency matrix:"<<endl;
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
 cin>>a[i][j];
 cout<<"\nBreath first traversal order:"<<endl;
/*for(i=1;i<=n;i++)
{
if(vi[i]==0)
	bfs(i);
}*/
int h;
cout<<"Enter from which element to be traversed:"<<endl;
cin>>h;
bfs(h);
return 0;
}
void bfs(int v)
{
count = count +1;
enqueue(v);
 vi[v]=count;
while(f!=0)
{
for(i=1;i<=n;i++)
{
if(i!=v && a[v][i]==1 && vi[i]==0)
{
enqueue(i);
vi[i]=count;
}
}
v = dequeue();
if(v!=-1)
cout<<v;
if(v==-1)
break;
}
}
