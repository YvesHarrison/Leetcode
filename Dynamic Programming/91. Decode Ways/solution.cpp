class Solution {
public:
    int numDecodings(string s) {
        if(s.size()==0||(s.size()==1&&s[0]-'0'==0)) return 0;
        vector<int>dp(s.size()+1);
        dp[s.size()]=1;
        if(s[s.size()-1]=='0')dp[s.size()-1]=0;
        else dp[s.size()-1]=1;
        for(int i=s.size()-2;i>=0;--i){
            if(s[i]-'0'==0)continue;
            else if((s[i]-'0')*10+s[i+1]-'0'<=26)dp[i]+=dp[i+2];
            dp[i]+=dp[i+1];
        }
        return dp[0];
    }
};
