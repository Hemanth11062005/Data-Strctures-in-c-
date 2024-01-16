#include <iostream>
using namespace std;

const int INF = 32767;
int weight[20][20], visited[20], d[20], p[20], v, e;

void creategraph() {
    cout << "\nEnter number of vertices"; cin >> v;
    cout << "\nEnter number of edges"; cin >> e;
    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++)
            weight[i][j] = 0;
    for (int i = 1; i <= v; i++) p[i] = visited[i] = 0, d[i] = INF;
    for (int i = 1, a, b, w; i <= e; i++) {
        cout << "\nEnter edges a, b and weight w:"; cin >> a >> b >> w;
        weight[a][b] = weight[b][a] = w;
    }
}

void prim() {
    int current = 1, totalvisited = 1, mincost, i;
    d[current] = 0; visited[current] = 1;
    while (totalvisited != v) {
        for (i = 1; i <= v; i++)
            if (weight[current][i] && !visited[i] && d[i] > weight[current][i])
                d[i] = weight[current][i], p[i] = current;
        mincost = INF;
        for (i = 1; i <= v; i++)
            if (!visited[i] && d[i] < mincost)
                mincost = d[i], current = i;
        visited[current] = 1; totalvisited++;
    }
    mincost = 0;
    for (i = 1; i <= v; i++) mincost += d[i];
    cout << "\nMinimum cost=" << mincost << "\nMinimum span tree is";
    for (i = 2; i <= v; i++) cout << "\nVertex " << i << " is connected to " << p[i];
}

int main() {
    cout << "\nMinimum spanning tree using PRIM'S ALGORITHM";
    creategraph(); prim(); return 0;
}
