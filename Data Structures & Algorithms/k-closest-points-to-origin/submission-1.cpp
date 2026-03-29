class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> pq;
        for(int i=0;i<points.size();i++){
            int x1 = points[i][0], y1 = points[i][1];
            double dist = x1*x1 + y1*y1;
            pq.push({dist,x1,y1});
            if(pq.size() > k)pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back({pq.top()[1], pq.top()[2]});
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
