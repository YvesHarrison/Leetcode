class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)return 0;
        vector<int>res(nums.size(),1);
        for(int i=1;i<nums.size();++i){
            int maxn=0;
            for(int j=0;j<i;++j){
                if(nums[j]<nums[i]){
                   maxn=max(res[j],maxn);//�ҵ�iǰ���������У���nums[i]���ڵ������еĽ�β���Լ����������
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
