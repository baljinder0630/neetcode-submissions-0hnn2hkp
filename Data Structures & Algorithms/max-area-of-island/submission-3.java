class Solution {
    public int solve(int[][] grid,int i,int j ,int m , int n){
        int[] dirX = {-1,1,0,0};
        int[] dirY = {0,0,-1,1};
        int ans = 1;
        grid[i][j] = -1;
        for(int index = 0 ; index < 4; index++){
            int newX = i + dirX[index];
            int newY = j + dirY[index];
            if(newX < 0 || newY < 0 || newX >= m || newY >= n)continue;
            if(grid[newX][newY] == 1){
            ans += solve(grid,newX,newY,m,n);
            }
        }
        return ans;
    }
    public int maxAreaOfIsland(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int ans = 0;
        for(int i=0;i < m ; i++){
            for(int j=0;j <n ;j++){
                if(grid[i][j] == 1)
                    ans = Math.max(ans, solve(grid,i , j, m , n));
            }
        }
        return ans; 
    }
}
