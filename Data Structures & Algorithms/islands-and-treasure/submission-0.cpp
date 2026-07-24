// class Solution {
// public:
//     int helper(int row,int col , vector<vector<int>>& grid,vector<vector<bool>>&vis){
//         if(row<0 || col<0 || row==grid.size()|| col == grid[0].size() || vis[row][col] || grid[row][col]==-1)
//             return 0 ;
//         vis[row][col]= true ;    
//         if(grid[row][col]==0){   
//             return 1;
//         }
//         if(grid[row][col]!=INT_MAX) return grid[row][col];
//       int left =helper(row-1,col,grid,vis);
//       int right =helper(row+1,col,grid,vis);
//       int up =helper(row,col-1,grid,vis);
//       int down =helper(row,col+1,grid,vis);
//         grid[row][col]=min(min(left,right),min(up,down)) +1 ;
//         return min(min(left,right),min(up,down)) +1;
        

//     }


//     void islandsAndTreasure(vector<vector<int>>& grid) {
//         int n= grid.size();
//         int m= grid[0].size();
        
//         vector<vector<bool>>vis(n,vector<bool>(m,false));
//         for(int i=0;i<n;i++){

//             for(int j=0;j<m;j++){
//                 if(!vis[i][j] && grid[i][j]==INT_MAX){
//                  int n =  helper(i,j,grid,vis);
//                 }

//             }
//         }
//         return ;
//     }
// };

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        // Push all gates
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0)
                    q.push({i, j});
            }
        }

        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(auto [dr, dc] : dir) {
                int nr = r + dr;
                int nc = c + dc;

                if(nr < 0 || nc < 0 || nr >= n || nc >= m)
                    continue;

                if(grid[nr][nc] != INT_MAX)
                    continue;

                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
};