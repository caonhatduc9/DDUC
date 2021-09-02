#include <iostream>
using namespace std;
#define MAX_VERTICES 7
struct graph
{
    int a[MAX_VERTICES][MAX_VERTICES];
    int n;
};
void initGraph(graph &g)
{
    for (int i = 0; i < g.n; i++)
        for (int j = 0; j < g.n; j++)
            g.a[i][j] = 0;
}
void show(graph g)
{
    for (int i = 0; i < g.n; i++)
    {
        for (int j = 0; j < g.n; j++)
            cout << g.a[i][j] << "\t";
        cout << endl;
    }
}
void addEdge(graph &g, int x, int y)
{
    g.a[x][y] = g.a[y][x] = 1;
}
int main()
{
    graph g;
    g.n = 5;
    initGraph(g);
    show(g);
    return 0;
}