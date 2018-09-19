class Solution {
public:
    int rob(vector<int>& nums) {
        int len=nums.size();
        if (len==0) return 0;
        vector<int>rec(len+1);
        rec[0]=nums[0];
        rec[1]=nums[1];
        if(len==2) return max(rec[0],rec[1]);
        rec[2]=max(rec[0]+nums[2],nums[1]);
        for(int i=3;i<len;++i){
            int t=max(rec[i-1],rec[i-2]+nums[i]);
            rec[i]=max(t,rec[i-3]+nums[i]);
        }
        rec[len]=max(rec[len-2],rec[len-1]);
        return rec[len];
    }
};
