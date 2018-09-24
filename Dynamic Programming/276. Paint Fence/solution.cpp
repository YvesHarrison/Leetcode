class Solution {
public:
    int numWays(int n, int k) {
        if(n==0||k==0||(n>2&&k==1))return 0;
        vector<int>dp(n,0);
        if(n==1)return k;
        if(n==2)return k*k;
        dp[0]=k;
        dp[1]=k*k;
        for(int i=2;i<n;++i){
            dp[i]=(k-1)*dp[i-1]+(k-1)*dp[i-2];//(k-1)*dp[i-1]means dp[i]does not have the same color as dp[i-1], dp[i] has k-1 choices; (k-1)*dp[i-2] means dp[i-1] and dp[i] are same color and they are not as same as the dp[i-2] so dp[i-1] and dp[i] has k-1 choices together
        }
        return dp[n-1];
    }
};
