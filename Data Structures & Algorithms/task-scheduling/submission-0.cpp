class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;
        for(auto it:tasks)freq[it]++;
        priority_queue<int> maxHeap; // store freq
        for(auto it:freq)maxHeap.push(it.second);
        queue<pair<int,int>> q; // store count left, next ideal time slot available
        int time = 0;
        while(!maxHeap.empty() || !q.empty()){
            if(!maxHeap.empty()){
                int top = maxHeap.top();
                maxHeap.pop();
                if(top > 1){
                    q.push({top-1,time+n});
                }
            }
            if(!q.empty()){
                if(q.front().second == time){
                    maxHeap.push(q.front().first);
                    q.pop();
                }
            }
            time++;
        }
        return time;
    }
};



// time = 3

// 2,4 1,5
