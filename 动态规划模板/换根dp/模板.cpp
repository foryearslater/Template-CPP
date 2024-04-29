//leetcode 834. 树中距离之和



/*
暴力做法：从i开始使用dfs到j，那么dep就是i到j的深度
*/

/*
换根dp
从0出发：计算其到每一个子树的距离之和
dfs同时计算出每个子树的大小

再次使用dfs从0出发进行dfs设y是x儿子
ans[y]=ans[x]+n-size[y]-size[y];
ans[y]=ans[x]+n-2*size[y];

*/
// class Solution {
    
// public:
//     vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
//         vector<vector<int>>g(n);
//         for(auto edge:edges){
//             int x=edge[0],y=edge[1];
//             g[x].push_back(y);
//             g[y].push_back(x);
//         }
//        vector<int>f(n);
//        vector<int>cnt(n,1);
//         function<void(int,int,int)>dfs1=[&](int u,int fa,int dep){
//            f[0]+=dep;
//                 for(auto x:g[u]){
//                    if(x==fa) continue;
//                    dfs1(x,u,dep+1);
//                    cnt[u]+=cnt[x];
//                 }
//         };
//          function<void(int,int)>dfs2=[&](int u,int fa){
//                 for(auto x:g[u]){
//                    if(x==fa) continue;
//                    f[x]=f[u]+n-2*cnt[x];
//                    dfs2(x,u);
//                 }
//         };
//         dfs1(0,-1,0);
//         dfs2(0,-1);
//         return f;
//     }
// };