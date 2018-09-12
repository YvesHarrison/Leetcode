class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>res(s.size()+1,false);
        res[0]=true;
        for(int i=0;i<s.size();++i){
            for(int j=i;j<s.size()&&res[i];++j){
                if(find(wordDict.begin(),wordDict.end(),s.substr(i,j-i+1))!=wordDict.end()){
                    res[j+1]=true;
                }
            }
        }        
        return res[s.size()];
    }
};
