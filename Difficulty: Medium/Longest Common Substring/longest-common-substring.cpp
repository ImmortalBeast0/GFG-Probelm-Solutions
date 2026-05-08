#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod ((int)1e9 + 7)

#define vi vector<int>
#define vii vector<vi>
#define pi pair<int, int>
#define vpi vector<pi>

#define pb push_back
#define bp pop_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()

class Solution {
  public:

    int n ,m;

    int dp[(int)1e3+1][(int)1e3+1];

    int rec(int i ,int j ,string& s ,string& t){
        if(i >= n || j >= m)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if(s[i] == t[j])
            ans = max(ans,1 + rec(i+1,j+1,s,t));

        return dp[i][j] = ans;
    }

    int longCommSubstr(string& s1, string& s2) {

        n = s1.size();
        m = s2.size();

        int ans = 0;
        memset(dp,-1,sizeof(dp));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                ans = max(ans,rec(i,j,s1,s2));
            }
        }

        return ans;
    }
};