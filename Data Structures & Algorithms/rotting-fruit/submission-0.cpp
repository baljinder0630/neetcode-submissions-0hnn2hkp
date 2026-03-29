class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    grid[i][j] = 0;
                }
            }
        }
        int dirX[] = {1,0,0,-1};
        int dirY[] = {0,1,-1,0};
        while(!q.empty()){
            auto [x,y] = q.front().first;
            int time = q.front().second;
            q.pop();
            ans = max(ans,  time);
            for(int i = 0; i< 4;i++){
                int newX = x + dirX[i];
                int newY = y + dirY[i];
                if(newX < 0 || newY < 0 || newX >= grid.size() || newY >= grid[0].size())continue;
                if(grid[newX][newY] == 0)continue;
                if(grid[newX][newY] == 1)q.push({{newX,newY},time+1});
                grid[newX][newY] = 0;
            }
        }
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return ans;
    }
};
