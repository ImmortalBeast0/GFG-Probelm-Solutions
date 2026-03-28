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

    vi vis;
    vii g;

    bool dfs(int u){
        
        vis[u] = 1;
        for(int v : g[u]){
            if(vis[v] == 1)
                return true;
            if(vis[v] == 0){
                if(dfs(v))
                    return true;
            }
        }

        vis[u] = 2;

        return false;
    }

    bool canFinish(int n_, vector<vector<int>>& pre) {

        // Check Whether DAG or NOT
        n = n_;
        vis.resize(n);
        g.resize(n);

        for(vector<int> edge : pre){
            int u = edge[0] ,v = edge[1];
            g[u].pb(v);
        }
        
        for(int i=0;i<n;i++)
            if(vis[i] == 0)
                if(dfs(i))
                    return false;

        return true;
    }
};