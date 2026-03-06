#include<bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
  public:
    int f1[27],f2[27];
    bool check(){
        for(int i=0;i<26;i++)
            if(f2[i] >= f1[i])
                continue;
            else
                return false;
        return true;    
    }
    void add(char c){
        f2[c-'a']++;
    }
    void rem(char c){
        f2[c-'a']--;   
    }
    string minWindow(string &s, string &p) {

        int n = s.length() ,m = p.length();
        string ans = "";
        memset(f1,0,sizeof(f1));
        memset(f2,0,sizeof(f2));
        for(auto c : p)
            f1[c - 'a']++;

        int i = 0 ,j = -1;
        for(;i<n;i++){
            while(j+1 < n && !check()){
                add(s[j+1]);
                j++;
            }
            if(check() && (ans.length() > (j-i+1) || ans == ""))
                ans = s.substr(i,j-i+1);
            
            rem(s[i]);
        }
        
        return ans;
    }
};