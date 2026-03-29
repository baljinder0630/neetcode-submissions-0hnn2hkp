class Solution {
public:
    static bool cmp(pair<int,int> &a, pair<int,int>& b){
        if(a.first == b.first)return a.second < b.second;
        return a.first > b.first;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int ans = 0;
        vector<pair<int,int>> arr;
        int n = position.size();
        for(int i=0;i<n;i++){
            arr.push_back({position[i],speed[i]});
        }
        sort(arr.begin(),arr.end(),cmp);
        stack<float> st;
        for(auto [d,s]:arr){
            // cout<<d<<" "<<s<<" ";
            if(st.empty()){
                st.push((target - d)/(float)s);
            }
            // cout << (target - d)/(float)s << endl;
            if(st.top() < (float)(target - d)/(float)s)st.push((target - d)/(float)s);
        }
        return st.size();
    }
};
