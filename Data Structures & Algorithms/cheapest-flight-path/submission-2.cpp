class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n,1e9);
        prices[src]=0;
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<tuple<int,int,int>> q;
        q.push(make_tuple(0,0,src));
        while(!q.empty()){
            auto [cost,curr_k,u] = q.front();
            q.pop();
            if(curr_k > k)continue;
            for(auto [v,wt]:adj[u]){
                if(prices[v] > wt + cost){
                    prices[v] = wt+cost;
                    q.push(make_tuple(prices[v],curr_k+1,v));
                }
            }
        }
        return prices[dst]== 1e9?-1:prices[dst];
    }
};
