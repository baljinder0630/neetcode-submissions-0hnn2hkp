class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(),deadends.end());
        if(visited.count("0000"))return -1;
        queue<pair<string,int>> q;
        q.push({"0000",0});
        visited.insert("0000");
        while(!q.empty()){
            auto [curr, count] = q.front();
            q.pop();
            if(curr == target)return count;
            for(int i=0;i < 4; i++){
                string front = curr;
                char ch= front[i];

                front[i] = ch == '0' ? '9' : ch - 1;    
                if(!visited.count(front)){
                    visited.insert(front);
                    q.push({front,count+1});
                }

                front[i] = ch == '9' ? '0' : ch + 1;
                if(!visited.count(front)){
                    visited.insert(front);
                    q.push({front,count+1});
                }
            }
        }
        return -1;
    }
};