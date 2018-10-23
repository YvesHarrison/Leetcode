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
    static bool cmp(const Interval& I1,const Interval& I2){
        return I1.start<I2.start;//&&I1.end<I2.end;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size()==0)return intervals;
        sort(intervals.begin(),intervals.end(),cmp);
        //for(int i=0;i<intervals.size();++i){
            //cout<<'['<<intervals[i].start<<','<<intervals[i].end<<']';
        //}
        for(int i=0;i<intervals.size()-1&&intervals.size()>=2;){
            if(intervals[i].end>=intervals[i+1].start&&intervals[i+1].end>=intervals[i].end){
                intervals[i].end=intervals[i+1].end;
                intervals.erase(intervals.begin()+1+i);
            }
            else if(intervals[i+1].end<intervals[i].end)intervals.erase(intervals.begin()+1+i);
            else i++;
        }        
        return intervals;
    }
};
