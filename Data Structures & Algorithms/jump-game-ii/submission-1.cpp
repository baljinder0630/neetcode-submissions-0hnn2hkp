class Solution {
public:
    int jump(vector<int>& nums) {
        queue<pair<int,int>> q;
        q.push({0,0});
        unordered_set<int> visited;
        visited.insert(0);
        while(!q.empty()){
            auto [index,count] = q.front();
            q.pop();
            if(index >= nums.size()-1)return count;
            for(int jump=1;jump<=nums[index];jump++){
                q.push({index+jump,count+1});
                visited.insert(index+jump);
            }
        }
        return -1;
    }
};
