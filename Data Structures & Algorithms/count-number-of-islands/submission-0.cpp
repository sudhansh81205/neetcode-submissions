class Solution {
public:
    int count =0;
    void  helper(int row,int col ,vector<vector<char>>& grid,int m,int n , vector<vector<bool>>&vis){
        if(row<0 || col<0 || row>=m || col>=n || vis[row][col] || grid[row][col]=='0' ){
            return  ;
        }
        vis[row][col]= true ; 
        helper(row+1,col,grid,m,n,vis);
        helper(row-1,col,grid,m,n,vis);
        helper(row,col-1,grid,m,n,vis);
        helper(row,col+1,grid,m,n,vis);
        
        return ;




    }


    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==false && grid[i][j]=='1'){
                    helper(i,j,grid,m,n,vis);
                    count++;
                }
            }
        }
        
        return count ;
    }
};
