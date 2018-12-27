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
    static bool cmp(Interval a,Interval b){
        return a.start<b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size()==0)return 0;
        sort(intervals.begin(),intervals.end(),cmp);
        
        int head=0;
        priority_queue<int, vector<int>, greater<int>> table;
    
        table.push(intervals[head].end);
        
        for(int i=1;i<intervals.size();++i){
            if(intervals[i].start>=table.top()){
                table.pop();
            }
            table.push(intervals[i].end);
        }
        return table.size();
    }
};