class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n=nums.size();
        int bucket[n+1]={0};
        for(int i=0;i<n;++i){
            bucket[nums[i]]++;
            if(bucket[nums[i]]>1) res.push_back(nums[i]);
        } 
        return res;
    }
};
