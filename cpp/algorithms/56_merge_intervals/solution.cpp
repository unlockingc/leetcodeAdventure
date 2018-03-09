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
        if (a.start < b.start)
            return true;
        if (a.start == b.start && a.end < b.end)
            return true;
        return false;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n < 2)
            return intervals;
        sort(intervals.begin(), intervals.end(), comp);
        int start = intervals[0].start;
        int end = intervals[0].end;
        Interval* ans;
        vector<Interval> res;
        for (int i = 1; i < n; i++) {
            if (intervals[i].start <= end) {
                start = min(start, intervals[i].start);
                end = max(end, intervals[i].end);
            } else {
                ans = new Interval(start, end);
                res.push_back(*ans);
                start = intervals[i].start;
                end = intervals[i].end;
            }
        }
        ans = new Interval(start, end);
        res.push_back(*ans);
        return res;
    }
};
