#include<bits/stdc++.h>
using namespace std;

#define mod (int)1e9+7
#define ll long long

#define vi vector<int>
#define vii vector<vi>
#define pi pair<int,int>
#define vpi vector<pi>

#define pb push_back
#define bp pop_back
#define mp make_pair

#define F first
#define S second 

#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()

class Solution {
  public:
    int n;
    vii g;

    vi depth;
    vi vis;
    vi parent;

    void dfs(int u ,int p,int d){

        parent[u] = p;
        vis[u] = 1;
        depth[u] = d;
        for(int v : g[u])
            if(p != v && !vis[v]){
                dfs(v,u,d+1);
            }

    }

    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        n = V;
        g.resize(n);
        vis.resize(n);
        depth.resize(n);
        parent.resize(n);

        for(vi edge : edges){
            int u = edge[0] ,v = edge[1];
            g[u].pb(v);
            g[v].pb(u);
        }

        dfs(0,-1,0);


        int v = 0;
        int maxx = 0;
        for(int i=0;i<n;i++)
            if(depth[i] > maxx){
                maxx = depth[i];
                v = i;
            }

        fill(all(vis),0);
        dfs(v,-1,0);
        int diameter = *max_element(all(depth));

        vi path;

        int farthest = max_element(all(depth)) - depth.begin();
        while(farthest != -1){
            path.pb(farthest);
            farthest = parent[farthest];
        }

        int sz = path.size();
        if(sz % 2)
            return {path[sz/2]};
        else
            return {path[sz/2 -1],path[sz/2]};
    }
};