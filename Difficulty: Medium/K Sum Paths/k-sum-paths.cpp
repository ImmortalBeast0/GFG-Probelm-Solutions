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

// class Node {
//   public:
//     int data;
//     Node *left;
//     Node *right;

//     Node(int val) {
//         data = val;
//         left = right = NULL;
//     }
// };

class Solution {
  public:

    unordered_map<ll,int> ump;
    // sum ,cnt;

    int k;
    int ans = 0;
    void dfs(Node *root ,ll sum){

        if(root == nullptr)
            return ;

       sum += root->data; 
       if(sum == k)
        ans += 1;
       if(ump.find(sum - k) != ump.end())
            ans += ump[sum - k];

        ump[sum] += 1;
        dfs(root->left,sum);
        dfs(root->right,sum);
        ump[sum] -= 1;
        if(ump[sum] == 0)
            ump.erase(sum);
        // sum -= root->data;
    }

    int countAllPaths(Node *root, int k_) {
        

        k = k_;
        ump[0] = 0;
        dfs(root,0);
        return ans;
    }
};