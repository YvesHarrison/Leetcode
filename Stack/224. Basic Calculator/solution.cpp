class Solution {
public:
    int calculate(string s) {
        int len=s.size(),res=0,num=0,sign=1;
        stack<int> nums,op;
        for(int i=0;i<len;++i){
            if(s[i]<='9'&&s[i]>='0')num=num*10+s[i]-'0';
            else{
                res+=sign*num;
                num=0;
                if(s[i]=='+')sign=1;
                else if(s[i]=='-')sign=-1;
                else if(s[i]=='('){
                    nums.push(res);
                    op.push(sign);
                    sign=1;
                    res=0;
                }
                else if(s[i]==')'){
                    res=nums.top()+res*op.top();
                    nums.pop();
                    op.pop();
                }
            }
        }
        res+=sign*num;
        return res;
    }
};
