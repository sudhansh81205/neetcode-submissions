class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c, int dist) {
        int n = grid.size();
        int m = grid[0].size();

        // Out of bounds
        if (r < 0 || c < 0 || r >= n || c >= m)
            return;

        // Wall
        if (grid[r][c] == -1)
            return;

        // If we've already found a shorter path
        if (grid[r][c] < dist)
            return;

        // Update distance
        grid[r][c] = dist;

        dfs(grid, r + 1, c, dist + 1);
        dfs(grid, r - 1, c, dist + 1);
        dfs(grid, r, c + 1, dist + 1);
        dfs(grid, r, c - 1, dist + 1);
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    dfs(grid, i, j, 0);
                }
            }
        }
    }
};

// class Solution {
// public:
//     void islandsAndTreasure(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();

//         queue<pair<int,int>> q;

//         // Push all gates
//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < m; j++) {
//                 if(grid[i][j] == 0)
//                     q.push({i, j});
//             }
//         }

//         vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

//         while(!q.empty()) {
//             auto [r, c] = q.front();
//             q.pop();

//             for(auto [dr, dc] : dir) {
//                 int nr = r + dr;
//                 int nc = c + dc;

//                 if(nr < 0 || nc < 0 || nr >= n || nc >= m)
//                     continue;

//                 if(grid[nr][nc] != INT_MAX)
//                     continue;

//                 grid[nr][nc] = grid[r][c] + 1;
//                 q.push({nr, nc});
//             }
//         }
//     }
// };