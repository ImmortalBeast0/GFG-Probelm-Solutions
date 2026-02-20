class Solution {
  public:
  
    static bool cmp(int a ,int b){
        string s = to_string(a) + to_string(b);
        string t = to_string(b) + to_string(a);
        return s > t;
    }
  
    string findLargest(vector<int> &arr) {
        
        int n = arr.size();
        sort(arr.begin(),arr.end(),cmp);
        
        string ans = "";
        for(int i=0;i<n;i++)
            ans += to_string(arr[i]);
            
        if(ans[0] == '0')
            return "0";
            
        return ans;
    }
};