class Solution {
public:
    int integerBreak(int n) {
        vector<long>rec(n+1);
        if(n==1)return 1;
        if(n==2)return 1;
        if(n==3)return 2;
        rec[2]=2;
        rec[3]=3;
        for(int i=4;i<=n;++i){
            if(rec[i-2]*2>rec[i-3]*3){
                rec[i]=rec[i-2]*2;
            }
            else if(rec[i-3]*3>=rec[i-2]*2){
                rec[i]=rec[i-3]*3;
            }
        }
        return rec[n];
    }
};
