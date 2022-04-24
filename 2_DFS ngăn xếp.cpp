#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <math.h>
#include <string.h>
using namespace std;

int n;
vector<vector<int>> e;
vector<bool> vs;
stack<int> st;
void dfs(int u)
{
    st.push(u);
    while (st.size() != 0)
    {
        int k = st.top();
        st.pop();
        if (vs[k] == false)
        {
            cout << k << " ";
            vs[k] = true;
        }
        for (int i = e[k].size()-1; i>=0; i--)
        {
            if (vs[e[k][i]]== 0)
            {
                st.push(e[k][i]);
            }
        }
    }
}

void solve()
{
    cin >> n;
    e.resize(n + 1);
    vs.resize(n + 1, false);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int x;
            cin >> x;
            if (x == 1)
                e[i].push_back(j);
        }
    }
    for(int i=0;i<e.size();i++)
    {
        sort(e[i].begin(),e[i].end());
    }
    dfs(1);
}

int main()
{
    solve();
    return 0;
}