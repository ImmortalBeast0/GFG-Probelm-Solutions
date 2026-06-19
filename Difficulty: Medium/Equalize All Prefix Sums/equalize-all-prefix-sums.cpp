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

    vi ps;
    int getSum(int l ,int r){
        if(l == 0)
            return ps[r];
        return ps[r] - ps[l-1];
    }

    int bs(int key ,vi& nums ,int ub){

        int n = nums.size();
        int ans = n - 1;
        int lb = 0;

        while(lb <= ub){
            int mi = (ub - lb)/2 + lb;
            if(nums[mi] <= key){
                ans = mi;
                lb = mi + 1;
            }else
                ub = mi - 1;
        }

        return ans;
    }

    vi optimalArray(vi& nums){

        // logic find the median every 0 ..... i
        // next (median - SUM[smallerElementThanOrEqualAMedian] + (SUM[greaterElementThanAMedian] - median))

        int n = nums.size();
        ps.resize(n);
        vi ans(n);  
        int sum = 0;

        for(int i=0;i<n;i++){
            sum += nums[i];
            ps[i] = sum;
            int median = nums[i/2];
            if(i % 2){
                median += nums[i/2+1];
                median /= 2;
            }
            int idx = bs(median,nums,i);
            int ltLen = (idx + 1);
            int rtLen = (i - (idx+1) + 1);
            ans[i] = (ltLen*median - getSum(0,idx)) + (getSum(idx+1,i) - median*rtLen);
        }

        return ans;
    }
};