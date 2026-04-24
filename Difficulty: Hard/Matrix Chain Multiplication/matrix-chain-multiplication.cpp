#include<bits/stdc++.h>
using namespace std;

#define mod ((int)1e9+7)
#define ll long long

#define vi vector<int>
#define vii vector<vi>
#define pi pair<int,int>
#define vpi vector<pi>

#define pb push_back
#define bp pop_back

#define F first
#define S second 

#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()

class Solution {
  public:

    int dp[132][132];

    int  rec(int i ,int j ,vi& arr){

        if(i+1 == j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 1e9;

        for(int k=i+1;k<j;k++){
            ans = min(ans,arr[i]*arr[k]*arr[j] + rec(i,k,arr) + rec(k,j,arr));
        }

        return dp[i][j] = ans;
    }

    int matrixMultiplication(vector<int> &arr) {
        
        int n = arr.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,n-1,arr);
    }
};
