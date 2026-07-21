class Solution {
public:
    bool helper(int idx1,int idx2,int n,int m ,string s,string p,vector<vector<int>>&dp){
        if(idx2 == m) return idx1 == n;
        bool firstMatch =(idx1 < n) && (s[idx1] == p[idx2] || p[idx2] == '.');
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(idx2 + 1 < m && p[idx2+1] == '*')
        {
            return dp[idx1][idx2]=helper(idx1, idx2+2, n, m, s, p,dp) ||      
                (firstMatch && helper(idx1+1, idx2, n, m, s, p,dp)); 
        }
        else
        {
            return dp[idx1][idx2]= firstMatch &&
                helper(idx1+1, idx2+1, n, m, s, p,dp);
        }
            }



    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(0,0,n,m,s,p,dp);
    }
};
