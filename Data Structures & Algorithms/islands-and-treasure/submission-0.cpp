class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        const int INF = 2147483647;
        queue<vector<int>> q;
        for(int i=0; i<grid.size();  i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 0){
                    q.push({i,j,0});
                }
            }
        }
        int dirX[] = {0,0,1,-1};
        int dirY[] = {1,-1,0,0};
        while(!q.empty()){
            auto v = q.front();
            int x = v[0];
            int y = v[1];
            int d = v[2];
            q.pop();
            for(int i=0; i < 4;i++){
                int newX = x + dirX[i];
                int newY = y + dirY[i];
                if(newX < 0 || newY < 0 || newX >= grid.size() || newY >= grid[0].size() || grid[newX][newY] == -1)continue;
                if(d + 1 < grid[newX][newY]){
                    grid[newX][newY] = d + 1;
                    q.push({newX,newY,d+1});
                }
            }
        }
    }
};
