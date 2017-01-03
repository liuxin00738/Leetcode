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
        int size=intervals.size();
        vector<Interval> result;
        if(intervals.size()==0){
            result.push_back(newInterval);
            return result;
        }
        
        // create a vector which has all the intervalsa
        vector<Interval> allIntervals;
        bool hasInserted=false;
        for(int i=0;i<intervals.size();i++){
            if(!hasInserted && newInterval.start<=intervals[i].start){
                allIntervals.push_back(newInterval);
            }
            allIntervals.push_back(intervals[i]);
        }
        if(!hasInserted)    allIntervals.push_back(newInterval);
        
        // merge intervals
        Interval curInterval=allIntervals[0];
        for(int i=1;i<allIntervals.size();i++){
            if(curInterval.end<allIntervals[i].start){
                result.push_back(curInterval);
                curInterval=allIntervals[i];
            }
            else{
                curInterval.end=max(curInterval.end, allIntervals[i].end);
            }
            
        }
             
        result.push_back(curInterval);
        
        return result;
    }
};
