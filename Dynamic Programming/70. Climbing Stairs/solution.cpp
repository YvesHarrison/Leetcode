class Solution {
public:
    int climbStairs(int n) {
        vector<int> rec(n+1);
        rec[0]=0;
        rec[1]=1;
        rec[2]=2;
        for(int i=3;i<n+1;++i){
            rec[i]=rec[i-1]+rec[i-2];
        }
        return rec[n];
    }
};
