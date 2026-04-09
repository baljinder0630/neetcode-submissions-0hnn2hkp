class Solution {
public:
    double dfs(string start,string end,auto& adj,auto& visited){
        if(start == end)return 1;
        visited.insert(start);
        for(auto [next,wt]:adj[start]){
            if(!visited.count(next)){
                double resp = dfs(next,end,adj,visited);
                if(resp != -1){
                    return resp * wt;
                }
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> adj;
        int n= equations.size();
        for(int i=0;i<n;i++){
            adj[equations[i][0]].push_back({equations[i][1],values[i]});
            adj[equations[i][1]].push_back({equations[i][0],1.0/values[i]});
        }
        vector<double> ans;
        for(auto query:queries){
            if(!adj.count(query[0]) || !adj.count(query[1])){
                ans.push_back(-1);
                continue;
            }
            unordered_set<string> visited;
            double resp = dfs(query[0],query[1],adj,visited);
            ans.push_back(resp);
        }
        return ans;
    }
};