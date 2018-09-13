class Solution {
public:
    void backtrack(string s,vector<string>&tmp,vector<vector<int>>&table,vector<vector<string>>&board,int pos){
        if(pos==s.size()){
            for(int i=0;i<tmp.size();++i){
                cout<<tmp[i]<<" ";
            }
            cout<<endl;
            board.push_back(tmp);
            return;
        }
        for(int i=pos;i<=pos;++i){
            for(int j=0;j<table[pos].size();++j){
                tmp.push_back(s.substr(i,table[i][j]-i+1));
                backtrack(s,tmp,table,board,table[i][j]+1);
                tmp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>res;
        vector<string>tmp;
        vector<vector<string>>board;
        vector<vector<int>>table(s.size());
        for(int i=0;i<s.size();++i){
            for(int j=i;j<s.size();++j){
                if(find(wordDict.begin(),wordDict.end(),s.substr(i,j-i+1))!=wordDict.end()){
                    table[i].push_back(j);
                }
            }
        }    
        backtrack(s,tmp,table,board,0);
        for(int i=0;i<board.size();++i){
            string a="";
            for(int j=0;j<board[i].size();++j){
                if(j!=board[i].size()-1)a+=board[i][j]+" ";
                else a+=board[i][j];
            }
            res.push_back(a);
        }
        return res;
    }
};
