class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> q;
        q.push(make_tuple(0,0,src));
        vector<vector<int>> dist(n,vector<int>(k+2,1e9));
        dist[src][0]=0;
        while(!q.empty()){
            auto front = q.top();
            q.pop();
            int cost = get<0>(front);
            int curr_k = get<1>(front);
            int u = get<2>(front);
            if(u == dst)return cost;
            if(curr_k > k)continue;
            for(auto [v,wt]:adj[u]){
                if(dist[v][curr_k+1] > cost + wt){
                    q.push({cost+wt,curr_k+1,v});
                    dist[v][curr_k+1+1]=cost+wt;
                }   
            }
        }   
        return -1;
    }
};
