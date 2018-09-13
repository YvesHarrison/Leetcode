class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<bool>res(s.size()+1,false);
        res[0]=true;
        for(int i=0;i<s.size();++i){
            for(int j=i;j<s.size()&&res[i];++j){
                if(find(wordDict.begin(),wordDict.end(),s.substr(i,j-i+1))!=wordDict.end()){
                    res[j+1]=true;
                }
            }
        }
        vector<string> empty;
        if(!res[s.size()])return empty;//judge string can be break or not escape from very long"aaaa...aaa"test case to avoid MLE or TLE
        vector<vector<string>>dp(s.size()+1);
        vector<string>start;
        start.push_back("");
        dp[0]=start;
        for (int i=1;i<=s.size();i++) {
            vector<string> list;
            for (int j = 0; j<i;j++) {
                if (dp[j].size()>0&& find(wordDict.begin(),wordDict.end(),s.substr(j,i-j))!=wordDict.end()) {
                    for (string l:dp[j]) {
                        if(l=="")list.push_back(l+s.substr(j,i-j));
                        else list.push_back(l+" "+s.substr(j,i-j));
                    }
                }
            }
            dp[i]=list;
        }
        return dp[s.size()];
    }
};
