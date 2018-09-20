class Solution {
public:
    int rob(vector<int>& nums) {
        int len=nums.size();
        if(len==0)return 0;
        if(len==1)return nums[0];
        if(len==2)return max(nums[0],nums[1]);
        vector<int>res(len);
        vector<int>res1(len);
        res[0]=nums[0];
        res1[1]=nums[1];
        res[1]=max(nums[0],nums[1]);
        for(int i=2;i<=len-2;++i){
            res[i]=max(res[i-1],res[i-2]+nums[i]);
        }
        res1[2]=max(nums[1],nums[2]);
        for(int i=3;i<=len-1;++i){
            res1[i]=max(res1[i-1],res1[i-2]+nums[i]);
        }
        return max(res[len-2],res1[len-1]);
    }
};
