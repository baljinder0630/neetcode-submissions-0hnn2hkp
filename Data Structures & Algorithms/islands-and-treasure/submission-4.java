class Solution {
    final int MAX = Integer.MAX_VALUE;
    public void islandsAndTreasure(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        Queue<int[]> q = new ArrayDeque<>();
        for(int i=0;i< m; i++){
            for(int j=0;j<n ;j++){
                if(grid[i][j] == 0){
                    q.offer(new int[]{i,j});
                }
            }
        }
        int dirX[] = {1,-1,0,0};
        int dirY[] = {0,0,1,-1};
        while(!q.isEmpty()){
            int[] front = q.poll();
            int x = front[0];
            int y = front[1];
            for(int index = 0; index < 4; index++){
                int newX = x + dirX[index];
                int newY = y + dirY[index];
                if(newX < 0 || newY < 0 || newX >= m || newY >= n)continue;
                if(grid[newX][newY] != MAX)continue;
                grid[newX][newY] = grid[x][y] + 1;
                q.offer(new int[]{newX,newY});
            }
        }
    }
}
