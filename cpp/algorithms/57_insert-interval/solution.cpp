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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
       
        if( intervals.size() == 0 )
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        
        
        int start = 0;
        int end = intervals.size();
        
        int startLocal = 0;
        int endLocal = 0;
        
        int temp = 0;
        while( start < end)
        {
            temp = start + (end - start)/2;
            
            if( intervals[temp].start == newInterval.start )
            {
                startLocal = temp;
                goto wangwang;
            }
            else if( intervals[temp].start < newInterval.start )
            {
                start = temp + 1;
            }
            else
            {
                end = temp;
            }
            //cout << "start: " << start << "  end: " << end << endl;
        }
        
        startLocal = end - 1;
        wangwang:
        start = 0;
        end = intervals.size();
        
        
        while( start < end)
        {
            temp = start + (end - start)/2;
            
            if( intervals[temp].end == newInterval.end )
            {
                endLocal = temp;
                goto wangwang1;
            }
            else if( intervals[temp].end < newInterval.end )
            {
                start = temp + 1;
            }
            else
            {
                end = temp;
            }
            //cout << "start: " << start << "  end: " << end << endl;
        }
        
        endLocal = end;
        wangwang1:
        
        //int deleteEnd = 0;
        //int startPlus1 = 0;
       // printf(" startLocal: %d\t endLocal: %d\n", startLocal, endLocal);
        
        if( ( startLocal == -1  || intervals[startLocal].end < newInterval.start) && (intervals[endLocal].start > newInterval.end  || endLocal == intervals.size()) && ( startLocal == endLocal -1 ))
        {
            intervals.insert(intervals.begin()+endLocal,newInterval);
            return intervals;
        }
        
        if( startLocal == -1 || intervals[startLocal].end < newInterval.start )
        {
            startLocal ++;
            intervals[startLocal].start = newInterval.start;
        }
        
        if( endLocal == intervals.size() || (intervals[endLocal].start > newInterval.end ) )
        {
            intervals[startLocal].end = newInterval.end;
        }
        else  
        {
            intervals[startLocal].end = intervals[endLocal].end;
            endLocal ++;
        }
        
        
        for( int i = startLocal + 1; i < endLocal; i ++ )
        {
            intervals.erase( (vector<Interval>::iterator)( &intervals[i] ) );
            i --;
            endLocal --;
        }
        
        return intervals;

    }
};