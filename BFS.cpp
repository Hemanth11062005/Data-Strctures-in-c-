#include <iostream>
#include <queue>
using namespace std;

int n, a[20][20], i, j;
int vi[10];
//int count = 0;

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
    queue<int> q;
    q.push(v);
    vi[v] = 1;

    while (!q.empty())
    {
        v = q.front();
        q.pop();

        for (i = 1; i <= n; i++)
        {
            if (i != v && a[v][i] == 1 && vi[i] == 0)
            {
                q.push(i);
                vi[i] = 1;
            }
        }

        cout << v << " ";
    }
}
