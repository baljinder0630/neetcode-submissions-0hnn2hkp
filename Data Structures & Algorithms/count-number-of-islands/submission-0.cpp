class Solution {
public:
    void bfs(auto& grid,int m,int n, int i,int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = '0';
        int dirX[] = {1,0,0,-1};
        int dirY[] = {0,-1,1,0};
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(int k = 0 ;k < 4; k++){
                int newX = x + dirX[k];
                int newY = y + dirY[k];
                if(newX >= 0 && newY >= 0 && newX < m && newY < n && grid[newX][newY] == '1'){
                    q.push({newX, newY});
                    grid[newX][newY] = '0';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i= 0 ; i < grid.size(); i++){
            for(int j = 0;j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    ans++;
                    bfs(grid,m,n,i,j);
                }
            }
        }
        return ans;
    }
};
