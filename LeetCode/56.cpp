/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool comp(Interval& a, Interval& b) {
        if (b.start > a.start)
            return true;
        if (b.start < a.start)
            return false;
        
        if (b.start > a.end)
            return true;
        
        if (b.end > a.end)
            return true;
        else
            return false;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        
        if (intervals.size() == 0)
            return intervals;
    
        vector<Interval> ans;
        std::sort(intervals.begin(), intervals.end(), comp);
        
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            Interval prev = ans.back();
            Interval cur = intervals[i];
            
            if (cur.start <= prev.end) {
                Interval p;
                p.start = prev.start;
                p.end = (cur.end > prev.end) ? cur.end : prev.end;
                ans.pop_back();
                ans.push_back(p);
            }
            else {
                ans.push_back(cur);
            }
        }
        
        return ans;
    }
};
