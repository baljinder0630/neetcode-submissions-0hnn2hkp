class Solution {
public:
    void dfs(string node,auto& adj,vector<string>& ans){
        while(!adj[node].empty()){
            string start = *adj[node].begin();
            adj[node].erase(adj[node].begin());
            dfs(start,adj,ans);
        }
        ans.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> adj;
        for(auto it:tickets){
            adj[it[0]].insert(it[1]);
        }
        vector<string> ans;
        dfs("JFK",adj,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
