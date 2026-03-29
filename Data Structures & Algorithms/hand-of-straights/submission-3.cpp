class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> freq;
        for(auto it:hand){
            freq[it]++;
        }
        for(auto it:hand){
            int start = it;
            while(freq[start -1] > 0)start--;
            if(start <= it && freq[start] > 0){
                int size= groupSize;
                while(size--){
                    if(freq[start] == 0)return false;
                    freq[start]--;
                    start++;
                }
            }
        }
        return true;
    }
};
