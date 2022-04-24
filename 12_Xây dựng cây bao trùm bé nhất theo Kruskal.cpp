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
struct Node
{
    int u, v;
    int value;

    Node(int u, int v, int value)
    {
        this->u = u;///diem dau
        this->v = v;//diem cuoi
        this->value = value;
    }
};
vector<Node> E;
int check[500] = {0};
int n;
bool cmp(Node a, Node b)
{
    if (a.value == b.value)
    {
        if (a.u == b.u)
        {
            return a.v < b.v;
        }
        return a.u < b.u;
    }
    return a.value < b.value;
}
void solve()
{
    cin >> n ;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int tmp;
            cin >> tmp;
            if (tmp >= 1)
            {
                if (i < j)
                    E.push_back(Node(i, j, tmp));
            }
        }
    sort(E.begin(), E.end(),cmp);
    int dH=0;
    vector<pair<int,int>> res;
    for(Node i:E)
    {
        if(check[i.u]==0||check[i.v]==0)
        {
            dH+=i.value;
            check[i.u]=1;
            check[i.v]=1;
            res.push_back({i.u,i.v});
        }
    }
    cout<<"dH = "<<dH<<endl;
    for(auto i:res)
    {
        cout<<i.first<<" "<<i.second<<endl;
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
}