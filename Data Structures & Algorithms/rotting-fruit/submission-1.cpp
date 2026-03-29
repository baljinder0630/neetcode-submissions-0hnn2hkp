class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;

        // initial scan
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        if(fresh == 0) return 0;

        int time = 0;
        int dirX[4] = {1, -1, 0, 0};
        int dirY[4] = {0, 0, 1, -1};

        while(!q.empty()){
            int sz = q.size();
            bool rotted = false;

            for(int k = 0; k < sz; k++){
                auto [x, y] = q.front(); q.pop();

                for(int d = 0; d < 4; d++){
                    int nx = x + dirX[d];
                    int ny = y + dirY[d];

                    if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                    if(grid[nx][ny] != 1) continue;

                    grid[nx][ny] = 2;
                    fresh--;
                    q.push({nx, ny});
                    rotted = true;
                }
            }

            if(rotted) time++;
        }

        return fresh == 0 ? time : -1;
    }
};
