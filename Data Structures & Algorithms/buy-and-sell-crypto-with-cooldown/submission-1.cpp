class Solution {
public:
    int helper(bool canbuy,int idx,int n,vector<int>& prices,vector<vector<int>>&dp){
        if(idx>=n) return 0;
        if(dp[idx][canbuy]!=-1) return dp[idx][canbuy] ;
        if(canbuy){
            int buy  =  helper(!canbuy,idx+1,n,prices,dp)-prices[idx];
        int notbuy = helper(canbuy,idx+1,n,prices,dp);
        return dp[idx][canbuy]=max(buy,notbuy);
        }
else{
        int sell = helper(!canbuy,idx+2,n,prices,dp)+prices[idx];
        int notsell = helper(canbuy,idx+1,n,prices,dp);
        return  dp[idx][canbuy]=max(sell,notsell);
        }
        return 0;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        bool canbuy = true ;
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(canbuy,0,n,prices,dp);
    }
};
