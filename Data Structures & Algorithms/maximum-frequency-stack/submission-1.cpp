class FreqStack {
public:
    int maxCount;
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> stacks;

    FreqStack() {
        maxCount = 0;    
    }
    
    void push(int val) {
        freq[val]++;
        stacks[freq[val]].push(val);
        int size = stacks[freq[val]].size();
        maxCount = max(maxCount, freq[val]);
    }
    
    int pop() {
        int val = stacks[maxCount].top();
        stacks[maxCount].pop();
        freq[val]--;
        if(stacks[maxCount].empty())maxCount--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */