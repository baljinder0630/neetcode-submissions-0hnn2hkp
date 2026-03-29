class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i=0;i<gas.size();i++){
            int sum = 0;
            for(int index = i; index < gas.size() + i;index++){
                sum += gas[index % gas.size()] - cost[index % gas.size()];
                if(sum < 0)break;
            }
            // cout<<sum << " ";
            if(sum >= 0)return i;
        }
        return -1;
    }
};
