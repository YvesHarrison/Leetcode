class Solution {
public:
    void backtrack(string s,vector<string>&tmp,vector<vector<int>>&table,vector<string>&res,int pos){
        if(pos==s.size()){
            string a="";
            
            for(int i=0;i<tmp.size();++i){
                if(i!=tmp.size()-1)a+=tmp[i]+" ";
                else a+=tmp[i];
            }
            res.push_back(a);
            return;
        }
        for(int i=pos;i<=pos;++i){
            for(int j=0;j<table[pos].size();++j){
                tmp.push_back(s.substr(i,table[i][j]-i+1));
                backtrack(s,tmp,table,res,table[i][j]+1);
                tmp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<bool>res1(s.size()+1,false);
        res1[0]=true;
        for(int i=0;i<s.size();++i){
            for(int j=i;j<s.size()&&res1[i];++j){
                if(find(wordDict.begin(),wordDict.end(),s.substr(i,j-i+1))!=wordDict.end()){
                    res1[j+1]=true;
                }
            }
        }
        vector<string> empty;
        if(!res1[s.size()])return empty;
        vector<string>res;
        vector<string>tmp;
        vector<vector<int>>table(s.size());
        for(int i=0;i<s.size();++i){
            for(int j=i;j<s.size();++j){
                if(find(wordDict.begin(),wordDict.end(),s.substr(i,j-i+1))!=wordDict.end()){
                    table[i].push_back(j);
                }
            }
        }    
        backtrack(s,tmp,table,res,0);
        
        return res;
    }
};
