class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int len=costs.size();
        if(len==0)return 0;
        vector<vector<int>>dp(len,vector<int>(3,0));
        dp[0][0]=costs[0][0];
        dp[0][1]=costs[0][1];
        dp[0][2]=costs[0][2];
        for(int i=1;i<len;++i){
            for(int j=0;j<3;++j){
                if(j==0)dp[i][j]=costs[i][j]+min(dp[i-1][1],dp[i-1][2]);
                else if(j==1)dp[i][j]=costs[i][j]+min(dp[i-1][0],dp[i-1][2]);
                else dp[i][j]=costs[i][j]+min(dp[i-1][1],dp[i-1][0]);
            }
        }
        return min(dp[len-1][0],min(dp[len-1][1],dp[len-1][2]));
    }
};
