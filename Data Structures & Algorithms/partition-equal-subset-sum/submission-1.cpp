class Solution {
public:
     bool helper(int idx, vector<int>& nums, int target,
                vector<vector<int>>& dp) {

        if (target == 0) return true;

        if (idx == 0) return nums[0] == target;

        if (dp[idx][target] != -1)
            return dp[idx][target];

        bool take = false;
        if (nums[idx] <= target)
            take = helper(idx - 1, nums, target - nums[idx], dp);

        bool nottake = helper(idx - 1, nums, target, dp);

        return dp[idx][target] = take || nottake;
    }


    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int sum=0;

        for(int i =0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        vector<vector<int>>dp(n,vector<int>((sum/2)+1,-1));
        return helper(n-1,nums,sum/2,dp);
    }
};
