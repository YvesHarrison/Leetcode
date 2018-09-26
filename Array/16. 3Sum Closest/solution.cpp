class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int res=INT_MAX;
        int sum=0;
        for(int k=nums.size()-1;k>=2;--k){
            for(int i=0,j=k-1;i<j;){
                if(abs(target-nums[i]-nums[j]-nums[k])<res){
                    res = abs(target-nums[i]-nums[j]-nums[k]);
                    sum = nums[i]+nums[j]+nums[k];
                    if(nums[i]+nums[j]+nums[k]<target)++i;
                    else --j;
                }
                else{
                    if(nums[i]+nums[j]+nums[k]<target)i++;
                    else j--;
                } 
            }
        }
        return sum;
    }
};
