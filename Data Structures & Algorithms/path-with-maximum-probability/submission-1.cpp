class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double> prob(n,0);
        priority_queue<pair<double,int>> pq;
        pq.push({1,start_node});
        while(!pq.empty()){
            auto [p, u] = pq.top();
            pq.pop();
            if(u == end_node)return p;
            for(auto [v,wt]:adj[u]){
                if(prob[v] < p * wt){
                    prob[v] = p * wt;
                    pq.push({prob[v],v});
                }
            }
        }
        return 0;
    }
};