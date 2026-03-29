/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool cmp(Interval& a,Interval& b){
        if(a.end == b.end)return a.start < b.start;
        return a.end < b.end;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int lastEndTime = intervals[0].end;
        for(int i = 1;i < intervals.size(); i++){
            if(intervals[i].start < lastEndTime)return false;
            lastEndTime = max(lastEndTime, intervals[i].end);
        }
        return true;
    }
};
