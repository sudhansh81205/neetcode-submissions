class Solution {
public:
    void helper(int row,int col ,vector<vector<char>>& board,vector<vector<bool>>&vis){
        if( row<0 || col<0 || row==board.size() || col==board[0].size() || board[row][col]=='X' || vis[row][col] ) return ;
        vis[row][col]=true;
        
        helper(row+1,col,board,vis);
        helper(row-1,col,board,vis);
        helper(row,col-1,board,vis);
        helper(row,col+1,board,vis);

        return ;
    }


    void solve(vector<vector<char>>& board) {
       int n= board.size();
       int m = board[0].size();

       vector<vector<bool>>vis(n,vector<bool>(m,false));
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='O' && (i==n-1 || j==m-1 || i==0 || j==0 ) && !vis[i][j]){
                helper(i,j,board,vis);
            }
        }
       } 
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='O' && !vis[i][j]){
                board[i][j]='X';
            }
        }
       } 
       return;
    }
};
