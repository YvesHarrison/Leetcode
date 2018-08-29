class Solution {
public:
    void backtracking(vector<vector<int>>&res,vector<int> &tmp,int n, int k, int pos){
        if(tmp.size()==k){
            res.push_back(tmp);
            return;
        }
        for(int i=pos;i<=n;++i){
            if(find(tmp.begin(),tmp.end(),i)!=tmp.end())continue;
            tmp.push_back(i);
            backtracking(res,tmp,n,k,i+1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;    
        backtracking(res,tmp,n,k,1);
        return res;
    }
};
