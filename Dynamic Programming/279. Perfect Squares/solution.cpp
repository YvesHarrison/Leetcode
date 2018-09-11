class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1);
        dp[1]=1;
        for(int i=2;i<=n;++i){
            int maxn=i;
            for(int j=1;j<=sqrt(i);++j){
                maxn=min(maxn,dp[i-j*j]);
            }
            dp[i]=maxn+1;
        }
        return dp[n];
    }
};
