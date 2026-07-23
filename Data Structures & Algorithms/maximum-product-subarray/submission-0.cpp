class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi=INT_MIN;
        for(int i =0;i<n;i++){
            int maxi1 =1;
            for(int j=i;j<n;j++){
                maxi1*=nums[j];
                maxi= max(maxi,maxi1);
            }
        }
        return maxi ;
    }
};
