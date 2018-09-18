class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>tmp;
        if(nums.size()==0||nums.size()<3)return res;
        if(count(nums.begin(),nums.end(),0)==nums.size()){
            tmp.push_back(0);
            tmp.push_back(0);
            tmp.push_back(0);
            res.push_back(tmp);
            return res;
        }
        sort(nums.begin(),nums.end());
        for(int k=nums.size()-1;k>=2;--k){
            int remain=0-nums[k];
            for(int i=0,j=k-1;;){
                if(i>=j)break;
                if(nums[i]+nums[j]>remain)j--;
                else if(nums[i]+nums[j]<remain)i++;
                else if(nums[i]+nums[j]==remain){
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    if(find(res.begin(),res.end(),tmp)==res.end())res.push_back(tmp);
                    tmp.clear();
                    i++;//without duplicate escape runs really slow 
                }
            }
        }
        return res;
    }
};
