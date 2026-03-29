class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int maxWt = 0;
        for(auto it:stones){
            maxWt = max(maxWt, it);
        }
        vector<int> bucket(maxWt+1,0);
        for(auto it:stones){
            bucket[it]++;
        }
        int first = maxWt;
        while(first > 0){
            while(first > 0 && bucket[first]==0)first--;
            if(first==0)return 0;
            bucket[first]--;
            int second=first;
            while(second>0 && bucket[second] == 0)second--;
            if(second==0)return first;
            bucket[second]--;
            bucket[abs(first-second)]++;
        }
        return 0;
    }
};
