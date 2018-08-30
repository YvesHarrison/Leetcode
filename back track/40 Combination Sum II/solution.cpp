class Solution {
public:
    void backtrack(vector<vector<int>> &res,vector<int>& candidates,vector<int> tmp,int target,int pos){
        if(target==0&&find(res.begin(),res.end(),tmp)==res.end()){
            res.push_back(tmp);
        }    
        for(int i=pos;i<candidates.size();++i){
            if(candidates[i]>target)continue;
            tmp.push_back(candidates[i]);
            backtrack(res,candidates,tmp,target-candidates[i],i+1);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>tmp;
        sort(candidates.begin(),candidates.end());
        
        backtrack(res,candidates,tmp,target,0);
        return res;
    }
};
