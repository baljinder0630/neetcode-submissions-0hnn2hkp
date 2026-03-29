class Solution {
public:
    static bool cmp(Interval& a,Interval& b){
        return a.start < b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it:intervals){
            if(!pq.empty() && pq.top() <= it.start)pq.pop();
            pq.push(it.end);
        }
        return pq.size();
    }
};
