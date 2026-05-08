class Solution {
    private void bfs(boolean[][] visited,Queue<int[]> q,int[][] heights,int m,int n){
        int dirX[] = {-1,1,0,0};
        int dirY[] = {0,0,-1,1};
        while(!q.isEmpty()){
            int[] front = q.poll();
            int x = front[0];
            int y = front[1];
            for(int i= 0 ; i < 4;i++){
                int newX = x + dirX[i];
                int newY = y + dirY[i];
                if(newX < 0 || newY < 0 || newX >= m || newY >= n)continue;
                if(heights[newX][newY] < heights[x][y])continue;
                if(visited[newX][newY])continue;
                visited[newX][newY] = true;
                q.offer(new int[]{newX,newY});
            }
        }
    }
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        int m = heights.length;
        int n = heights[0].length;
        List<List<Integer>> ans = new ArrayList<>();
        Queue<int[]> pacQ = new ArrayDeque<>();
        Queue<int[]> atlQ = new ArrayDeque<>();
        boolean[][] pacVisited = new boolean[m][n];
        boolean[][] atlVisited = new boolean[m][n];
        for(int i = 0 ;i  < m ; i++){
            for(int j = 0;j < n ; j++){
                pacVisited[i][j] = false;
                atlVisited[i][j] = false;
                if(i == 0 || j == 0){
                    pacQ.offer(new int[]{i,j});
                    pacVisited[i][j] = true;
                }
                if(i == m-1 || j == n-1){
                    atlQ.offer(new int[]{i,j});
                    atlVisited[i][j] = true;
                }
            }
        }
        bfs(pacVisited,pacQ,heights,m,n);
        bfs(atlVisited,atlQ,heights,m,n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacVisited[i][j] && atlVisited[i][j]){
                    ans.add(Arrays.asList(i,j));
                }
            }
        }
        return ans;
    }
}
