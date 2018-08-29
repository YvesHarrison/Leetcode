class Solution {
public:
    void backtrack(vector<vector<int>> &res,vector<int>tmp,int k,int n){
        if(tmp.size()==k and n==0){
            res.push_back(tmp);
        }
        else{
            int flag;
            if(tmp.empty())flag=1;
            else flag=tmp[tmp.size()-1]+1;//强制按大小顺序排列值，避免1，2，4和2，1，4出现,避免1，1出现
            for(int i=flag;i<=9;i++){//只能在1-9选
                if(find(tmp.begin(),tmp.end(),i)!=tmp.end()) continue;
                else{
                    tmp.push_back(i);
                    backtrack(res,tmp,k,n-i);
                    tmp.pop_back();
                }
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int>tmp;
        backtrack(res,tmp,k,n);
        return res;
    }
};
