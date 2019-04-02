class Solution {
public:
    string reverseOnlyLetters(string S) {
        string tmp="";
        for(int i=0;i<S.size();++i){
            if((S[i]-'a'<26&&S[i]-'a'>=0)||(S[i]-'A'<26&&S[i]-'A'>=0))tmp+=S[i];
        }
        int start=0,end=tmp.size()-1;
        while(start<end){
            swap(tmp[start++],tmp[end--]);
        }
        for(int i=0;i<S.size();++i){
            if(!((S[i]-'a'<26&&S[i]-'a'>=0)||(S[i]-'A'<26&&S[i]-'A'>=0))){
                tmp=tmp.substr(0,i)+S[i]+tmp.substr(i,tmp.size()-i);
            }
        }
        return tmp;
    }
};
