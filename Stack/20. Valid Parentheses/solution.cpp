class Solution {
public:
    bool compare(char a,char b){
        if(a=='('&&b==')')return true;
        else if(a=='['&&b==']')return true;
        else if(a=='{'&&b=='}')return true;
        else return false;
    }
    bool isValid(string s) {
        if(s.size()==0)return true;
        if(s.size()%2)return false;
        stack<char> res;
        for(int i=0;i<s.size();++i){
            if(s[i]=='{'||s[i]=='('||s[i]=='[')res.push(s[i]);
            else{
                if(res.empty())return false;
                if(compare(res.top(),s[i]))res.pop();
                else return false; 
            }
        }
        if(res.empty())return true;
        else return false;
    }
};
