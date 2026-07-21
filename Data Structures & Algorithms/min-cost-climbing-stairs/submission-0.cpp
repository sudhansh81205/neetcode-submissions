

class Solution {
public:
    int helper(int n ,vector<int>&dp,vector<int>& cost){
          if(n<0) return INT_MAX ;
           if (n <= 1)
            return dp[n]= cost[n];
         if(dp[n]!=-1) return dp[n]   ;
        return dp[n]=min(helper(n-1,dp,cost),helper(n-2,dp,cost)) + cost[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
         vector<int>dp(n+1,-1);
        return min(helper(n-1, dp, cost), helper(n-2, dp, cost));
    }
};
