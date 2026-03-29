class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> qr;
        for(int i=0;i<queries.size();i++){
            qr.push_back({queries[i],i});
        }
        sort(qr.begin(),qr.end());
        vector<int> ans(queries.size(),-1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        int i=0;
        for(auto query:qr){
            while(i < intervals.size() && intervals[i][0] <= query[0]){
                pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }
            while(!pq.empty() && pq.top().second < query[0]){
                pq.pop();
            }
            if(!pq.empty()){
                ans[query[1]] = pq.top().first;
            }
            else{
                ans[query[1]] = -1;
            }
        }
        return ans;
    }
};
