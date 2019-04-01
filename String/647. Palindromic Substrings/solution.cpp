class Solution {
public:
    int countSubstrings(string s) {
        if(s.size()==0)return 0;
        int res=0,start,end;
        for(int i = 0;i < s.size();++i){
            start = i;
            end = i;
            res++;
            while(end + 1 < s.size() && s[start] == s[end + 1]){
                res++;
                end++;
            }
            while(start - 1 > -1 && end + 1 < s.size() && s[start - 1] == s[end + 1]){
                res++;
                start--;
                end++;
            }
        }
        return res;
    }
};
