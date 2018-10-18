class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size()+2;
        vector<vector<int>>dp(n,vector<int>(n,0));
        vector<int>num(n,1);
        for(int i=0;i<n-2;++i){
            num[i+1]=nums[i];
        }
        for(int len=2;len<n;len++){
            for(int left=0;left<n-len;++left){
                int right=left+len;
                for(int mid=left+1;mid<right;++mid){
                    dp[left][right]=max(dp[left][right],dp[left][mid]+dp[mid][right]+num[mid]*num[left]*num[right]);//dp(left,right) repersents the max coins getting from the range, treat every mid as the last balloon to burst find, the result of (left,right) relies on reuslts of (left,mid) and (mid,right)  
                }
                //cout<<left<<" "<<right<<" "<<dp[left][right]<<endl;
            }
        }
        return dp[0][n-1];
    }
};
