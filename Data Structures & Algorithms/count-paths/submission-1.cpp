class Solution {
public:int count = 0;
    int helper(int m , int n ,int x,int y,vector<vector<int>>&dp){
        if(x>=m || y>=n || x<0 || y<0 ){
            return 0;
        }
        if(dp[x][y]!=-1) return dp[x][y];
        if(x==0 && y==0) {
            return dp[x][y]=1;}

        return dp[x][y]=helper(m,n,x-1,y,dp) + helper(m,n,x,y-1,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(m,n, m-1,n-1,dp);
        
    }
};
