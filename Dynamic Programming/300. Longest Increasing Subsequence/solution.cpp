class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)return 0;
        vector<int>res(nums.size(),1);
        for(int i=1;i<nums.size();++i){
            int maxn=0;
            for(int j=0;j<i;++j){
                if(nums[j]<nums[i]){
                   maxn=max(res[j],maxn);//找到i前最大递增序列，且nums[i]大于递增序列的结尾可以加入递增序列
                }
            }
            res[i]=maxn+1;
        }
        int cnt=1;
        for(int i=0;i<nums.size();++i){
            cnt=max(cnt,res[i]);
        }
        return cnt;
    }
};
