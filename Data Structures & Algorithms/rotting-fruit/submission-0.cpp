class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        // Put all rotten oranges into the queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        if(fresh == 0) return 0;

        int minutes = 0;

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};

        while(!q.empty()) {

            int sz = q.size();
            bool rottenThisMinute = false;

            while(sz--) {

                auto [x,y] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++) {

                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1) {

                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx,ny});
                        rottenThisMinute = true;
                    }
                }
            }

            if(rottenThisMinute)
                minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};