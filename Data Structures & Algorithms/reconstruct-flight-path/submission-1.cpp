class Solution {
public:
    void dfs(string node,auto& adj,vector<string>& ans){
        for(auto& it:adj[node]){
            if(!it.second){
                it.second = true;
                dfs(it.first, adj, ans);
            }
        }
        ans.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<pair<string,bool>>> adj;
        for(auto it:tickets){
            adj[it[0]].push_back({it[1],false});
        }
        for(auto &it:adj){
            sort(it.second.begin(),it.second.end());
        }
        vector<string> ans;
        dfs("JFK",adj,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
