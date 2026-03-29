class Solution {
    public int swimInWater(int[][] grid) {
        int N = grid.length;
        PriorityQueue<int[]> minHeap = new PriorityQueue<>((a,b)->a[0]-b[0]);
        boolean[][] visit = new boolean[N][N];
        int dir[][] = {
            {0,1},{1,0},{-1,0},{0,-1}
        };
        minHeap.offer(new int[]{grid[0][0],0,0});
        visit[0][0]=true;
        while(!minHeap.isEmpty()){
            int[] curr = minHeap.poll();
            int t = curr[0], x = curr[1], y = curr[2];
            if(x == N-1 && y == N-1)return t;
            for(int i=0;i<4;i++){
                int newX = x + dir[i][0];
                int newY = y + dir[i][1];
                if(newX < 0 || newY < 0 || newX >= N || newY >= N || visit[newX][newY])
                    continue;
                else{
                    minHeap.offer(new int[]{
                        Math.max(t, grid[newX][newY]), newX,newY
                    });
                    visit[newX][newY] = true;
                }
            }
        }
        return N*N;
    }
}
