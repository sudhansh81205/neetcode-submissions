class Solution {
public:
    
    int helper(int idx,int amount,vector<int>coins,vector<vector<int>>&dp){
        if(idx<0) return 0;
        if(amount==0 ) return dp[amount][idx]=1;

        if(dp[amount][idx]!=-1) return dp[amount][idx];
        int take =0;
        if(amount>=coins[idx])take= helper(idx,amount-coins[idx],coins,dp);
        int not_take= helper(idx-1,amount,coins,dp);
        return dp[amount][idx]=take+not_take; 
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(amount+1,vector<int>(n,-1));
        return helper(n-1,amount,coins,dp);
    }
};
