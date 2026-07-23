class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi=INT_MIN;
        vector<int>dp(n,-1);
        for(int i =0;i<n;i++){
            int maxi1 =1;
            for(int j=i;j<n;j++){
                if(dp[j]!=-1) {maxi = max(maxi,maxi1*dp[j]);
                    continue ;
                }
                maxi1*=nums[j];

                maxi= max(maxi,maxi1);
            }
            dp[i]= maxi;
        }
        return maxi ;
    }
};
