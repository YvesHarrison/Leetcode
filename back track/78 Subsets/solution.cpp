class Solution {
public:
    void backtrack(vector<vector<int>>&res,vector<int>&tmp,vector<int>&nums,int pos){
        if(find(res.begin(),res.end(),tmp)==res.end()){
            res.push_back(tmp);//子集1（1步）和1，2，3（3步）是不同搜索步长的搜索，完成一个搜索不可中断直接加入结果集，依据该搜索进行下一步搜索，以新的检查条件返回，完成在不等步搜索的各步均有结果返回
        }
        if(tmp.size()==nums.size()||pos==nums.size())return;
        for(int i=pos;i<nums.size();++i){
            //if(find(tmp.begin(),tmp.end(),nums[i])!=tmp.end())continue;
            tmp.push_back(nums[i]);
            backtrack(res,tmp,nums,i+1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>tmp;
        res.push_back(tmp);
        backtrack(res,tmp,nums,0);
        return res;
    }
};
