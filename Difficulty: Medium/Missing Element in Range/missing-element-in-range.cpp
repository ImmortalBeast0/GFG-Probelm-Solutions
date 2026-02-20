class Solution {
  public:
  
    //Binary Serach
    int n;
    bool check(vector<int>& nums ,int key){
        
        int lb = 0 ,ub = n - 1;
        
        while(lb <= ub){
            int mi = (ub - lb)/2 + lb;
            if(key == nums[mi])
                return true;
            else if(key < nums[mi])
                ub = mi - 1;
            else
                lb = mi + 1;
        }
        
        return false;
    }
  
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        
        n = arr.size();
        vector<int> ans;
        
        sort(arr.begin(),arr.end());
        
        for(int i=low;i<=high;i++)
            if(check(arr,i))
                continue;
            else
                ans.push_back(i);
        
        return ans;
    }
};