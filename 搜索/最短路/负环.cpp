#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int, int> pii;
#define N 30010
int t;
vector<pii> g[N];
bool st[N];
int dist[N];
int cnt[N];
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        g[i].clear(), st[i] = false, dist[i] = INT_MAX, cnt[i] = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        if(w<0)
        g[a].push_back({b, w});
        else{
             g[a].push_back({b, w});
             g[b].push_back({a, w});
        }
    }
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    st[1] = true;
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        st[t] = false;
        for (auto x : g[t])
        {
            int a = x.first, b = x.second;
            if (dist[a] > dist[t] + b)
            {
                dist[a] = dist[t] + b;
                cnt[a] = cnt[t] + 1;
                if (cnt[a] >= n)
                {
                    cout << "YES" << endl;

                    return;
                }
                if (!st[a])
                {
                    st[a] = true, q.push(a);
                }
            }
        }
    }
    cout << "NO" << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}