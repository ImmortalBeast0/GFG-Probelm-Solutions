#include<bits/stdc++.h>
using namespace std;

#define mod 1e9 + 7
#define ll long long
#define vi vector<int>
#define vii vector<vi>
#define pi pair<int,int>
#define vpi vector<pi>

#define pb push_back
#define bp pop_back
#define mp make_pair

#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()

class Solution {
  public:

    int dp[52][52];
    int rec(int i ,int sum ,int n ,int m ,int x){
        if(i >= n){
            return sum == x;
        }

        if(sum > x){
            return 0;
        }

        if(dp[i][sum] != -1)
            return dp[i][sum];

        int ans = 0;
        for(int d=1;d<=m;d++){
            ans += rec(i+1,sum+d,n,m,x);
        }

        return dp[i][sum] = ans;
    }

    int noOfWays(int m, int n, int x){
       memset(dp,-1,sizeof(dp));
       return rec(0,0,n,m,x); 
    }
};

// x 

// _ _ _ _ _ _  ==> N spaces 

// m - possiblity 
