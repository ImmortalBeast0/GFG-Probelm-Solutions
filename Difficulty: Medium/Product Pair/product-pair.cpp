class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target){
        
            
        unordered_map<long long,int> mp;
        for(int x : arr){
            if(x != 0 && target % x ==0 && mp.find(target/x) != mp.end())
                return true;
            mp[x]++;
        }
        
        return false;
    }
};