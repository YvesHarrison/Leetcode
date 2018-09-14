class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        string res;
        int len_max=0,start=0,end=0;
        if(len==0)return res;
        vector<vector<bool>>table(len,vector<bool>(len,false));
        table[0][0]=true;
        for(int i=1;i<len;++i){
            table[i][i]=true;
            if(s[i]==s[i-1])table[i-1][i]=true;
        }
        for(int i=0;i<len;++i){
            for(int j=0;j<i;++j){
                if(s[i]==s[j]&&table[j+1][i-1])table[j][i]=true;
                if(table[j][i]&&i-j+1>len_max){
                    start=j;
                    end=i;
                    len_max=i-j+1;
                }
            }
        }
        return s.substr(start,end-start+1);
    }
};
