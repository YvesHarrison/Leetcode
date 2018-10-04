class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mi=0x7fffffff,sum=0;
        int len=nums.size();
        if(len==1) return 0;
        for(int i=0;i<len;i++){
            sum+=nums[i];
            mi=min(nums[i],mi);
        }
        return sum-mi*len;
    }
};
