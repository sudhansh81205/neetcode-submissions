class Solution {
public:
    int helper(int row,int col , vector<vector<bool>>&vis,
    vector<vector<int>>& grid,int n,int m){
        if(row<0 || col<0 || row>=n || col>=m || grid[row][col]==0 || vis[row][col]){
            return 0 ;
        }
        vis[row][col]= true ;
        int up = helper(row+1,col,vis,grid,n,m);
        int down =helper(row-1,col,vis,grid,n,m);
        int left= helper(row,col-1,vis,grid,n,m);
        int right =helper(row,col+1,vis,grid,n,m);
        return up+down+left+right+1;

    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n  = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int maxi =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==false || grid[i][j]==1){
                    maxi= max(maxi, helper(i,j,vis,grid,n,m));

                }
            }
        }

       return maxi ;
    }
};
