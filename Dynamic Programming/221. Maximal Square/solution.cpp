class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row=matrix.size();
        if(row==0)return 0;
        int col=matrix[0].size();
        int res=0;
        // vector<vector<int>>dp(row+1,vector<int>(col+1,0));
        // for(int i=1;i<=row;++i){
        //     for(int j=1;j<=col;++j){
        //         if(matrix[i-1][j-1]=='1'){
        //             dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
        //             res=max(res,dp[i][j]);
        //         }
        //     }
        // }O(mn)space
        int pre=0;
        vector<int>dp(col+1,0);
        for(int i=1;i<=row;++i){
            for(int j=1;j<=col;++j){
                int tmp=dp[j];
                if(matrix[i-1][j-1]=='1'){
                    dp[j]=min(dp[j],min(dp[j-1],pre))+1;
                    res=max(res,dp[j]);
                }
                else dp[j]=0;
                pre=tmp;//O(n)space
            }
        }
        return res*res;
    }
};
