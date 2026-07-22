class Solution {
public:
    int helper(int idx,string s,int n ,vector<int> &dp){
        if(idx>=n) return 1 ;
        if(dp[idx]!=-1) return dp[idx];
        int count =0 ;
        int one= s[idx]-48 ;
        if(one==0) return dp[idx]=0 ; 
        count = helper(idx+1,s,n,dp) ;
        if(idx+1<n){
        int two = one*10 + (s[idx+1]-48);
        if(two<27 && two>9) count += helper(idx+2,s,n,dp);
        }
        return dp[idx]= count ;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n,-1);
        return helper(0, s,n,dp);
    }
};
