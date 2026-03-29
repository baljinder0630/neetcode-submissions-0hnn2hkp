class Solution {
public:
    int dfs(auto& grid,int i,int j){
        int dirX[] = {-1,0,0,1};
        int dirY[] = {0,-1,1,0};
        int ans = 1;
        for(int k=0; k < 4; k++){
            int newX = dirX[k] + i;
            int newY = dirY[k] + j;
            if(newX < 0 || newY < 0 || newX >= grid.size() || newY >= grid[0].size() || !grid[newX][newY]){
                continue;
            }
            grid[newX][newY] = 0;
            ans += dfs(grid, newX, newY);
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0;i < grid.size(); i++){
            for(int j= 0 ; j < grid[0].size(); j++){
                if(grid[i][j]){
                    grid[i][j] = 0;
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }
};
