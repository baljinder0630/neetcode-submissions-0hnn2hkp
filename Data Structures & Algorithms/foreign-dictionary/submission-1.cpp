class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, set<char>> adj;
        unordered_map<char, int> indegree;

        // ✅ Initialize all characters with indegree 0
        for (auto &word : words) {
            for (char c : word) {
                indegree[c] = 0;
            }
        }

        // ✅ Build graph
        for (int i = 0; i < words.size() - 1; i++) {
            string &s1 = words[i];
            string &s2 = words[i + 1];
            int len = min(s1.size(), s2.size());

            // ❌ Invalid case: prefix problem
            if (s1.size() > s2.size() && s1.substr(0, len) == s2) {
                return "";
            }

            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    if (!adj[s1[j]].count(s2[j])) {
                        adj[s1[j]].insert(s2[j]);
                        indegree[s2[j]]++;
                    }
                    break;
                }
            }
        }

        // ✅ Kahn’s algorithm
        queue<char> q;
        for (auto &it : indegree) {
            if (it.second == 0) q.push(it.first);
        }

        string ans = "";
        while (!q.empty()) {
            char node = q.front();
            q.pop();
            ans.push_back(node);

            for (char nei : adj[node]) {
                if (--indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        // ❌ Cycle detected
        if (ans.size() != indegree.size()) return "";

        return ans;
    }
};
