class Solution {
public:
    void backtracking(vector<vector<int>>&res,vector<int> tmp, vector<int> nums){
        if(tmp.size()==nums.size()){
            res.push_back(tmp);
        }
        else{
            for(int i=0;i<nums.size();++i){
                if(find(tmp.begin(),tmp.end(),nums[i])!=tmp.end()) continue;
                tmp.push_back(nums[i]);
                backtracking(res,tmp,nums);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int> tmp;
        backtracking(res,tmp,nums);
        return res;
    }
};
