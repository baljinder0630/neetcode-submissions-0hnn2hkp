class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        int l=0, r = m[key].size();
        while(l < r){
            int mid = (l+r)/2;
            if(m[key][mid].first > timestamp){
                r = mid;
            }
            else l = mid + 1;
        }
        if(l == 0)return "";
        return m[key][l-1].second;
    }
};
