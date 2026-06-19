#include<bits/stdc++.h>
using namespace std;

#define mod ((int)1e9+7)
#define ll long long

#define vi vector<int>
#define vii vector<vi>
#define pi pair<ll,ll>
#define vpi vector<pi>

#define F first
#define S second
#define pb push_back
#define bp pop_back
#define mp make_pair
#define all(x) x.begin(),x.end()

class Solution {
  public:

    int getSum(int l ,int r ,int *ps){
        
        if(l == 0)
            return ps[r];
        return ps[r] - ps[l - 1];
    }

    int findCoverage(vector<vector<int>>& mat){

        int m = mat.size();
        int n = mat[0].size();

        int col[n][m];
        int row[m][n];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                col[j][i] = mat[i][j];
                row[i][j] = mat[i][j];
                if(i > 0)
                    col[j][i] += col[j][i-1];
                if(j > 0)
                    row[i][j] += row[i][j-1];
            }
        }

        
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    ans += getSum(0,j,row[i]) >= 1;
                    ans += getSum(j,n-1,row[i]) >= 1;
                    ans += getSum(0,i,col[j]) >= 1;
                    ans += getSum(i,m-1,col[j]) >= 1;
                }
            }
        }

        return ans;
    }
};
