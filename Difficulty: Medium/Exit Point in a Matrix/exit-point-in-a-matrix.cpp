class Solution {
  public:
    int m ,n;
    bool isBountry(int i ,int j){
        return i < 0 || i >= m || j < 0 || j >= n;
    }
  
    vector<int> exitPoint(vector<vector<int>>& mat){
        
        m = mat.size();
        n = mat[0].size();
        int i = 0 ,j = 0;
        int dx[4] = {-1,0,1,0} ,dy[4] = {0,1,0,-1};
        int k = 1;
        while(true){
            if(isBountry(i,j)){
                return {i - dx[k],j - dy[k]};
            }
            if(mat[i][j] == 0){
                i += dx[k];
                j += dy[k];
            }else{
                k = (k + 1) % 4;
                mat[i][j] = 0;
                i += dx[k];
                j += dy[k];
            }
        }
        
        return {-1,-1};
    }
};