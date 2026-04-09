class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        pq.push(make_tuple(0,0,0));
        set<pair<int,int>> visited;
        int dirX[] = {1,-1,0,0};
        int dirY[] = {0,0,1,-1};
        while(!pq.empty()){
            auto [diff, x, y] = pq.top();
            pq.pop();
            if(visited.count({x,y}))continue;
            visited.insert({x,y});
            if(x == m-1 && y == n-1)return diff;
            for(int i=0;i<4;i++){
                int newX = x + dirX[i];
                int newY = y + dirY[i];
                if(newX < 0 || newY < 0 || newX >= m || newY >= n)continue;
                pq.push(make_tuple(max(diff, abs(heights[newX][newY] - heights[x][y])),newX,newY));
            }
        }
        return -1;
    }
};