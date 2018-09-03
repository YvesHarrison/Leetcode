class Solution {
public:
    void backtrack(vector<vector<char>> table,vector<string> &res,string tmp,string digits,int pos){
        if(tmp.length()==digits.length()){
            res.push_back(tmp);
            return;
        }
        for(int i=pos;i<pos+1;++i){
            for(int j=0;j<table[(digits[i]-'0')-2].size();++j){
                tmp+=table[(digits[i]-'0')-2][j];
                backtrack(table,res,tmp,digits,pos+1);
                tmp.resize(tmp.length()-1);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<vector<char>> table{{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
        vector<string> res;
        if(digits.empty())return res;//[]空，[""]向量里有一个空字符串向量本身不为空
        string tmp;
        backtrack(table,res,tmp,digits,0);
        return res;
    }
};
