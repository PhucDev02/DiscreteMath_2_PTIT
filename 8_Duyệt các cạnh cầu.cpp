#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
using namespace std;
int V, E;
int mt[150][150];
vector<int> vs;
int lienthong;
void dfs(int s)
{
    stack<int> st;
    st.push(s);
    vs[s] = 1;

    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        // cout<<u<<" ";
        for (int i = 1; i <= V; i++)
        {
            int x = mt[u][i];
            if (x == 1 && vs[i] == 0)
            {
                vs[i] = 1;
                st.push(i);
            }
        }          
    }
    // cout<<endl;
}
int checkcanhcau(int i, int j)
{
    vs.clear();
    vs.resize(V + 1, 0);
    mt[i][j] = 0;
    int tmp = 0;
    for (int x = 1; x <= V; x++)
    {
        if (vs[x] == 0)
        {
            tmp++;
            dfs(x);
        }
    }
    mt[i][j] = 1;
    return tmp > lienthong;
}
void solve()
{
    lienthong = 0;
    int x, y;
    cin >> V;
    vs.clear();
    vs.resize(V + 1, 0);
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            cin >> mt[i][j];
        }
    }
    for (int i = 1; i <= V; i++)
    {
        if (vs[i] == 0)
        {
            lienthong++;
            dfs(i);
        }
    }
    // cout<<lienthong;
    for (int i = 1; i <= V; i++)
    {
        for (int j = i; j <= V; j++)
        {
            if (mt[i][j] == 1)
            {
                if (checkcanhcau(i, j))
                    cout << i << " " << j << endl;
            }
        }
    }
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
    return 0;
}