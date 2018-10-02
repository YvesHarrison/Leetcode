class Solution {
public:
    string toLowerCase(string str) {
        string res="";
        for(int i=0;i<str.size();++i){
            if(int(str[i])>=65&&int(str[i])<=90)res+=char(int(str[i])+32);
            else res+=str[i];
        }
        return res;
    }
};
