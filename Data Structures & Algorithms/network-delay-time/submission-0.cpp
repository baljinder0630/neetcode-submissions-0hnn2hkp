class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,1e9);
        dist[k]=0;
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times){
            int u=it[0], v=it[1], w=it[2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto [d,u] = pq.top();
            pq.pop();
            for(auto [v,w]:adj[u]){
                if(d + w < dist[v]){
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = 0;
        for(int i=1;i <=n;i++){
            if(dist[i] == 1e9)return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
