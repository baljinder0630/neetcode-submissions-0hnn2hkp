class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        const int INF = 2147483647;
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int dirX[4] = {0, 0, 1, -1};
        int dirY[4] = {1, -1, 0, 0};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dirX[k];
                int ny = y + dirY[k];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != INF)
                    continue;

                grid[nx][ny] = grid[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
};
