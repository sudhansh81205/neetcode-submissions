class Solution {
public:
    bool helper(int idx1,int idx2,int n,int m,int k ,string s1,string s2,string s3,vector<vector<int>>&dp){
        if(idx1==n && idx2==m && idx1+idx2==k){
            return true ;
        }
        if(idx1+idx2==k) return false ;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        bool take_s1;
        bool take_s2;
        if(s1[idx1]==s3[idx1+idx2]) take_s1= helper(idx1+1,idx2,n,m,k,s1,s2,s3,dp);
        if(s2[idx2]==s3[idx1+idx2]) take_s2 = helper(idx1,idx2+1,n,m,k,s1,s2,s3,dp);
        return dp[idx1][idx2]= take_s1 | take_s2 ;
    }



    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int k = s3.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        if(k>n+m || k<n+m) return false;
       return helper(0,0,n,m,k,s1,s2,s3,dp);
    }
};
