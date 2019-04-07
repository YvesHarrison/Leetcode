class Solution {
public:
    string build(string S){
        stack<char>s;
        for(int i = 0; i < S.size(); ++i){
            if(S[i] != '#') s.push(S[i]);
            else if(!s.empty() && S[i] == '#') s.pop();
        }
        string res = "";
        while(!s.empty()){
            res += s.top();
            s.pop();
        }
        return res;
    }
    
    bool backspaceCompare(string S, string T) {
        S = build(S);
        T = build(T);
        return S == T;
    }
};
