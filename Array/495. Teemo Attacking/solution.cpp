class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int len=timeSeries.size();
        if(len==0) return 0;
        int cn=0;
        for(int i=1;i<len;++i){
            if(timeSeries[i]-timeSeries[i-1]>=duration)cn+=duration;
            else cn+=timeSeries[i]-timeSeries[i-1];
        }
        return cn+duration;
    }
};
