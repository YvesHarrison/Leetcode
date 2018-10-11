class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int len1=s.size(),len2=t.size();
        if(len1==0&&len2==0)return false;
        if(s==t)return false;
        if(abs(len1-len2)>1)return false;
        int diff=0;
        if(len1==len2){
            for(int i=0;i<len1;++i){
                if(s[i]!=t[i])diff++;
                if(diff>1)return false;
            }
        }
        else{
            if(len1>len2){
                for(int i=0;i<len2;++i){
                    if(s[i]==t[i])continue;
                    else if(t[i]==s[i+1]&&t[i]!=s[i])continue;
                    else if(t[i]!=s[i+1]&&t[i]!=s[i])return false;
                }
            }
            else{
                for(int i=0;i<len1;++i){
                    if(s[i]==t[i])continue;
                    else if(t[i+1]==s[i]&&t[i]!=s[i])continue;
                    else if(t[i+1]!=s[i]&&t[i]!=s[i])return false;
                }
            }
            
        }
        return true;
    }
};
