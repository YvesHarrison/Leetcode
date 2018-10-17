class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=2;i<=n;++i){
            for(int j=1;j<=n-i+1;++j){
                int minus=INT_MAX;
                for(int k=j;k<j+i-1;++k){
                    int res=k+max(dp[j][k-1],dp[k+1][j+i-1]);
                    minus=min(res,minus); 
                }
                dp[j][j+i-1]=minus;
            }
        }
        return dp[1][n];
    }
};
