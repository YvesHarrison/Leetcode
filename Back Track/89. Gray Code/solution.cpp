class Solution {
public:
    void backtrack(vector<int>&res,int n,int start){
        if(res.size()==pow(2,n)){
            return;
        }
        for(int i=0;i<n;++i){
            int new_start=start^(1<<i);
            if(find(res.begin(),res.end(),new_start)!=res.end())continue;
            res.push_back(new_start);
            backtrack(res,n,new_start);
        }
    }
    vector<int> grayCode(int n) {
        vector<int>res;
        res.push_back(0);
        backtrack(res,n,0);
        return res;
    }
};
