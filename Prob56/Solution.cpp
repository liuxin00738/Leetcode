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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if(intervals.size()==0) return result;
        
        sort(intervals.begin(), intervals.end(), myfunction); 
        Interval curInterval=intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(curInterval.end>=intervals[i].start){
                curInterval.end=max(curInterval.end,intervals[i].end);
                continue;
            }
            result.push_back(curInterval);
            curInterval.start=intervals[i].start;
            curInterval.end=intervals[i].end;
        }
        result.push_back(curInterval);
        return result;
    }
    
private:
    static bool myfunction (const Interval& lhs, const Interval& rhs) 
    { 
        return (lhs.start<rhs.start); 
    }

};
