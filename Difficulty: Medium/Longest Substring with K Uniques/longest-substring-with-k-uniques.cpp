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


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
  public:
    int n;

    int atmostK(string &s ,int k){

        unordered_map<char,int> mpp;
        int i = 0 ,j = -1 ,ans = -1;

        for(;i<n;i++){
            while(j+1 < n){
                mpp[s[j+1]]++;
                if(mpp.size() > k){
                    mpp[s[j+1]]--;
                    if(mpp[s[j+1]] == 0)
                        mpp.erase(s[j+1]);
                    break;
                }
                j += 1;
            }
            if(mpp.size() == k)
                ans = max(ans ,j - i + 1);

            mpp[s[i]]--;
            if(mpp[s[i]] == 0)
                mpp.erase(s[i]);
        }

        return ans;
    }

    int longestKSubstr(string &s, int k){
        n = s.length();
        return atmostK(s,k);
    }
};