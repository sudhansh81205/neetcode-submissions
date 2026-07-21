class Solution {
public:
    int helper(int idx,vector<int>&nums,bool prev,vector<vector<int>>&dp){
        if(idx<0) return 0;
        if(dp[idx][prev]!=-1) return dp[idx][prev] ;

        int taken=INT_MIN;
        if(prev==false) taken = helper(idx-1,nums,true,dp)+nums[idx];
        int not_taken= helper(idx-1,nums,false,dp);
        return dp[idx][prev]= max(taken,not_taken);
    }


    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(n-1,nums,false,dp);
    }
};
