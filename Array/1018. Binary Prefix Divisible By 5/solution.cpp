class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool>res;
        long num=0;
        for(int i=0;i<A.size();++i){
            num=(num*2+A[i])%5;
            if(num==0)res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};
