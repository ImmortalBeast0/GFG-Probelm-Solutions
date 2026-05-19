class Solution {
  public:
  
    int minSteps(vector<int>& arr, int start, int end){
        
        start %= 1000;
        end %= 1000;
        int ans_depth = 0;
        queue<int> q;
        unordered_map<int,bool> mp;
        
        q.push(start);
        mp[start] = true;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int u = q.front();
                q.pop();
                if(u == end)
                    return ans_depth;
                for(int x : arr){
                    int v = (u * x) % 1000;
                    if(mp.find(v) == mp.end()){
                        mp[v] = true;
                        q.push(v);
                    }
                }
            }
            ans_depth += 1;
        }
        
        return -1;
    }
};