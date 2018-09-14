class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>num;
        vector<int>res;
        for(int i=0;i<nums.size();++i){
            num[nums[i]]=i+1;
        }
        for(int i=0;i<nums.size();++i){
            if(num[target-nums[i]]>0&&num[target-nums[i]]-1!=i){
                res.push_back(i);
                res.push_back(num[target-nums[i]]-1);
                return res;
            }
        }
        return res;
    }
};
