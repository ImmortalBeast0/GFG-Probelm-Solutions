class Solution {
  public:
  
    vector<vector<int>> adj;
    vector<int> vis;
    int colors = 0;
    
    bool check(int node ,int col){
        for(int v : adj[node]){
            if(vis[v] == col)
                return false;
        }
        return true;
    }
    
    bool rec(int i){
        
        if(colors > 2)
            return true;
        
        if(i == adj.size())
            return false;
        
        for(int c=0;c<colors;c++){
            if(check(i,c)){
                vis[i] = c;
                if(rec(i+1))
                    return true;
            }
        }
        
        if(vis[i] == -1){
            colors += 1;
            vis[i] = colors-1;
            if(rec(i+1))
                return true;
        }
        
    }
  
    bool isBipartite(int V, vector<vector<int>> &edges) {
    
        adj.resize(V);
        vis.resize(V,-1);
        
        for(vector<int> e : edges){
            int u = e[0] ,v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return !rec(0);
    }
};