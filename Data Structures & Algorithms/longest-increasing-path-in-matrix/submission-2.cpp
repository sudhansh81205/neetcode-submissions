class Solution {
public:
    int helper(int row,int col ,int n,int m ,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        if(row<0 || col<0 || row==n || col==m ){
            return 1;
        }
        if(dp[row][col]!=-1) return dp[row][col];
        int p1=INT_MIN;
        int p2=INT_MIN;
        int p3=INT_MIN;
        int p4=INT_MIN;
        if(row-1>=0 && matrix[row-1][col]>matrix[row][col]){
            p1 = helper(row-1,col,n,m,matrix,dp)+1;  
        }
        if(row+1<n && matrix[row+1][col]>matrix[row][col]){
            p2 = helper(row+1,col,n,m,matrix,dp)+1;  
        }
        if(col-1>=0 && matrix[row][col-1]>matrix[row][col]){
            p3 = helper(row,col-1,n,m,matrix,dp)+1;  
        }
        if(col+1<m && matrix[row][col+1]>matrix[row][col]){
            p4 = helper(row,col+1,n,m,matrix,dp)+1;  
        }
        int maxi = max(max(p1,p2),max(p3,p4));
        if(maxi==INT_MIN) return dp[row][col]= 1 ;
        else return dp[row][col]= maxi;

        return dp[row][col]=1;
        
     }




    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi = INT_MIN;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxi =max(maxi, helper(i,j,n,m,matrix,dp)) ;
            }
        }
        return maxi;
    }
};

