#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <stack>
#include <queue>
#include <set>
#define maxx 105
using namespace std;
int adj[50][50], trace[50], vis[50];
int n, s, t;
bool hPath = false;

void init() {
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }
}

void findPath(int i) {
    if (i == s) return;
    cout << trace[i] << " ";
    findPath(trace[i]);
}

void dfs(int u) {
    vis[u] = 1;
    if (hPath) {
        return;
    }
    if (u == t) {
        hPath = true;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (adj[u][i] && !vis[i]) {
            trace[i] = u;
            dfs(i);
        }
    }
}

void bfs(int u) {
    queue<int> q;
    q.push(u);
    vis[u] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == t) {
            hPath = true;
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (adj[u][i] && !vis[i]) {
                vis[i] = 1;
                trace[i] = u;
                q.push(i);
            }
        }
    }
}

void solve() {
    dfs(s);
    if (!hPath) {
        cout << "no path" << "\n";
        return;
    }
    cout << "DFS path: " << t << " ";
    findPath(t);
    cout << "\n";

    memset(vis, 0, sizeof(vis));
    memset(trace, 0, sizeof(trace));

    hPath = false;
    bfs(s);
    cout << "BFS path: " << t << " ";
    findPath(t);
}

int main() {
    init();
    solve();
}