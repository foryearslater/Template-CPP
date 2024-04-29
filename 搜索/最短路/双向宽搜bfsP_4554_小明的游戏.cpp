#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int, int> pii;
#define N 800
char s[N][N];
int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, 1, -1, 0};
int a, b, c, d;
int n, m;  
int dist[N][N];
/*
双端队列优化
如果相等就放前面优先考虑
否则放在后面再进行考虑
*/
int bfs()
{
    memset(dist,-1,sizeof dist);
    dist[a][b] = 0;
    deque<pii> q;
    q.push_front({a, b});
    while (q.size())
    {
        auto t = q.front();
        q.pop_front();
        // cout<<t.first<<" "<<t.second<<endl;
        for (int i = 0; i < 4; i++)
        {
            int xx = dx[i] + t.first, yy = t.second + dy[i];
            if (dist[xx][yy] >= 0)
                continue;
            if (xx >= 0 && xx < n && yy >= 0 && yy < m)
            {
                if (s[xx][yy] != s[t.first][t.second])
                {
                    q.push_back({xx, yy});
                    dist[xx][yy] = dist[t.first][t.second] + 1;
                }
                else
                {
                    q.push_front({xx, yy});
                    dist[xx][yy] = dist[t.first][t.second];
                }
            }
            if (xx == c && yy == d)
            {
                return dist[xx][yy];
            }
        }
    }
    return 0;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   
    while (cin >> n >> m)
    {
        if (m == 0 && n == 0)
            break;
        
        for (int i = 0; i < n; i++)
            cin >> s[i];
         cin >> a >> b >> c >> d;
         cout<<bfs()<<endl;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++) cout<<dist[i][j]<<" ";
        //     cout<<endl;
        // }
    }

    return 0;
}