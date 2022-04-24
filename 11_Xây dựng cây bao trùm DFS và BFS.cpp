#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#define maxx 1000007
#define xd cout << endl;
#define ll long long
using namespace std;
int a[500][500];
int check[500] = {0};
int n, u;
void dfs(int u)
{
    check[u] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[u][i] == 1 && check[i] == 0)
        {
            if (u < i)
            {
                cout << u << " " << i << "\n";
            }
            else
                cout << i << " " << u << "\n";
            dfs(i);
        }
    }
}
void bfs(int u)
{
    check[u] = 1;
    queue<int> q;
    q.push(u);
    while (q.size())
    {
        int tmp = q.front();
        q.pop();
        for (int i = 1; i <= n; i++)
        {
            if (a[tmp][i] == 1 && check[i] == 0)
            {
                if (tmp < i)
                {
                    cout << tmp << " " << i << "\n";
                }
                else
                    cout << i << " " << tmp << "\n";
                check[i] = 1;
                q.push(i);
            }
        }
    }
}
void solve()
{
    cin >> n >> u;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    cout << "DFS tree\n";
    dfs(u);
    for (int i = 1; i <= n; i++)
        check[i] = 0;
    cout << "BFS tree\n";
    bfs(u);
}
int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}