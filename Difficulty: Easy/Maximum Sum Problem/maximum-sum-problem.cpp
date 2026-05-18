class Solution {
  public:
    int dp[(int)1e6+132];
    int rec(int n){
        if(n <= 3)
            return 0;
            
        if(dp[n] != -1)
            return dp[n];
            
        int ans = (n/2 + n/3 + n/4);
        ans = max(n,ans);
        ans = max(ans ,rec(n/2) + rec(n/3) + rec(n/4));
        
        return dp[n] = ans;
    }
  
    int maxSum(int n){
        memset(dp,-1,sizeof(dp));
        return max(n,rec(n));
    }
};
