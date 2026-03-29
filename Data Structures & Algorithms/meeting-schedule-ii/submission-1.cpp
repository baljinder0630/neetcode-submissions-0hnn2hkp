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
    int minMeetingRooms(vector<Interval>& intervals) {
        // line sweep algo
        map<int,int> events;
        for(auto it:intervals){
            events[it.start]++;
            events[it.end]--;
        }
        int ans = 0, eventCount= 0;
        for(auto it:events){
            eventCount += it.second;
            ans = max(eventCount, ans);
        }
        return ans;
    }
};
