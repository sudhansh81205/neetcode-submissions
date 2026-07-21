class Solution {
public:
    int helper(int idx, int sum, vector<int>& nums,
               vector<vector<int>>& dp) {

        if (idx == nums.size())
            return (sum == 0);

        if (dp[idx][sum + 1000] != -1)
            return dp[idx][sum + 1000];

        int plus = helper(idx + 1, sum - nums[idx], nums, dp);

        int minus = helper(idx + 1, sum + nums[idx], nums, dp);

        return dp[idx][sum + 1000] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        vector<vector<int>> dp(nums.size(),
                               vector<int>(2001, -1));

        return helper(0, target, nums, dp);
    }
};