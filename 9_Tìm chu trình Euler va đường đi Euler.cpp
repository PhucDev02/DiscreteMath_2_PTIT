#include <iostream>
#include <vector>
#include <stack>
#define MAX 100
using namespace std;

class Graph
{
public:
    int n, a[MAX][MAX];
    int dinhCanDuyet;
    void readData();
    void init();
    void dfs(int u);
};

void Graph::readData()
{
    cin >> n;
    cin >> dinhCanDuyet;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    init();
}
void Graph::init()
{
}
void Graph::dfs(int u)
{
    stack<int> st;
    vector<int> CE;
    st.push(u);
    while (st.size())
    {
        int s = st.top();
        bool KeRong = true;
        for (int i = 1; i <= n; i++)
        {
            if (a[s][i])
            {
                st.push(i);
                KeRong = false;
                a[s][i] = a[i][s] = 0;
                break;
            }
        }
        if (KeRong == true)
        {
            st.pop();
            CE.push_back(s);
        }
    }
    for (int i = CE.size() - 1; i >= 0; i--)
        cout << CE[i] << " ";
}
int main()
{
    Graph x;
    x.readData();
    x.dfs(x.dinhCanDuyet);
}