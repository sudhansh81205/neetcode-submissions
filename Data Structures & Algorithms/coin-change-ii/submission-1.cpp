// class Solution {
// public:
    
//     int helper(int idx,int amount,vector<int>coins,vector<vector<int>>&dp){
//         if(idx<0) return 0;
//         if(amount==0 ) return dp[amount][idx]=1;

//         if(dp[amount][idx]!=-1) return dp[amount][idx];
//         int take =0;
//         if(amount>=coins[idx])take= helper(idx,amount-coins[idx],coins,dp);
//         int not_take= helper(idx-1,amount,coins,dp);
//         return dp[amount][idx]=take+not_take; 
//     }
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         vector<vector<int>>dp(amount+1,vector<int>(n,-1));
//         return helper(n-1,amount,coins,dp);
//     }
// };

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(amount + 1, vector<int>(n, 0));

        // Base case: amount = 0
        for (int idx = 0; idx < n; idx++)
            dp[0][idx] = 1;

        for (int amt = 1; amt <= amount; amt++) {
            for (int idx = 0; idx < n; idx++) {

                int take = 0;
                if (amt >= coins[idx])
                    take = dp[amt - coins[idx]][idx];

                int notTake = 0;
                if (idx > 0)
                    notTake = dp[amt][idx - 1];

                dp[amt][idx] = take + notTake;
            }
        }

        return dp[amount][n - 1];
    }
};
