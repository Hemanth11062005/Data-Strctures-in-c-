#include <iostream>
#include <queue>
using namespace std;

int n, a[20][20], i, j,q[10],f=-1,r=-1;
int vi[10];
//int count = 0;
void push(int i){
if(f==-1 && r==-1){
    f=1;r=1;
}
else{
    r++;
}
    q[r]=i;

}

int front( ){
    return q[f];
}
void pop(){
    if(f>r)
        f = -1;
    else{
        //int value = q[f];
        f++;
    }
}

void bfs(int);

int main()
{
    cout << "\nEnter the number of vertices";
    cin >> n;

    for (i = 1; i <= n; i++)
        vi[i] = 0;

    cout << "\nEnter the adjacency matrix";
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> a[i][j];

    int x;
    cout << "Enter which to traverse:" << endl;
    cin >> x;
    cout << "\nBreadth First Traversal order :";
    bfs(x);

    return 0;
}

void bfs(int v)
{
    push(v);
    vi[v] = 1;

    while (f!=-1)
    {
        v = front();
        pop();

        for (i = 1; i <= n; i++)
        {
            if (i != v && a[v][i] == 1 && vi[i] == 0)
            {
                push(i);
                vi[i] = 1;
            }
        }

        cout << v << " ";
    }
}
