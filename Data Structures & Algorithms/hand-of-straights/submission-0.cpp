class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0)return false;
        unordered_map<int,int> freq;
        for(auto it:hand){
            freq[it]++;
        }
        sort(hand.begin(),hand.end());
        //   2  3  4 5
        for(int i=0;i<hand.size();i++ ){
            int size = groupSize;
            int val = hand[i];
            while(size > 0 && freq[val] > 0){
                cout<<val << "," << size << " ";
                freq[val]--;
                val++;
                size--;
            }
            cout<<endl;
            if(size > 0 && size < groupSize)return false;
        }
        for(auto it:hand)if(freq[it] > 0)return false;
        return true;
    }
};
