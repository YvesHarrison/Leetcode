class Solution {
public:
    void find(vector<string>&res,string tmp,int left,int right,int n){
        if(tmp.size()==2*n){
            res.push_back(tmp);
            return;
        }
        if(left<n)find(res,tmp+'(',left+1,right,n);
        if(right<left)find(res,tmp+')',left,right+1,n);//无显式的删除已加入节点
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        if(n==0)return res;
        string tmp;
        find(res,tmp,0,0,n);
        return res;
    }
};
