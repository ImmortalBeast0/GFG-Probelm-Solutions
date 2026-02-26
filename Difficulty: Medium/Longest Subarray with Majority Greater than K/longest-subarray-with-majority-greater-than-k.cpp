#include <bits/stdc++.h>
using namespace std;

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
#define sz(x) x.size()

#define mod (1e9) + 7
#define inf 1e9

using ll = long long;

class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        
        int n = arr.size();

        for(int i=0;i<n;i++)
            arr[i] = arr[i] <= k ? -1 : 1;

        unordered_map<int,int> mp;
        //mp sum , idx only store early sum ,intially 0
        mp[0] = -1;

        int curSum = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            curSum += arr[i];
            if(curSum > 0)
                ans = i+1;
            if(mp.find(curSum - 1) != mp.end()){
                ans = max(ans,i - mp[curSum - 1]);
            }
            if(mp.find(curSum) == mp.end())
                mp[curSum] = i;
        }

        return ans;
    }
};