class DSU{
public:
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findParent(int a){
        if(parent[a] == a)return a;
        return parent[a] = findParent(parent[a]);
    }

    void unionAll(int a,int b){
        int pa = findParent(a);
        int pb = findParent(b);
        if(pa == pb)return;
        if(size[pa] > size[pb]){
            size[pa] += size[pb];
            parent[pb] = pa;
        }
        else{
            size[pb] += size[pa];
            parent[pa] = pb;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);
        unordered_map<string,int> emailToAcc;
        for(int i=0;i<n;i++){
            for(int j =1; j < accounts[i].size(); j++){
                if(emailToAcc.count(accounts[i][j])){
                    dsu.unionAll(i,emailToAcc[accounts[i][j]]);
                }else
                    emailToAcc[accounts[i][j]]=i;
            }
        }
        unordered_map<int,vector<int>> res;
        for(int i=0;i<n;i++){
            int parent = dsu.findParent(i);
            res[parent].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto it:res){
            set<string> s;
            cout<<it.first<<":";
            for(auto childs:it.second){
                cout<<childs<<" ";
                for(int i=1;i< accounts[childs].size();i++){
                    s.insert(accounts[childs][i]);
                }
            }
            cout<<endl;
            vector<string> temp;
            temp.push_back(accounts[it.first][0]);
            for(auto it:s){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};