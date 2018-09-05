class Solution {
public:
    string generate(int i,int n){
        string res;
        for(int j=0;j<n;++j){
            if(j==i)res+='Q';
            else res+='.';
        }
        return res;
    }
    bool check(vector<string>&sol,int i,int j,int n){//i为新行行号，依靠已有的sol判断新行的放置位置是否可行，保证生成的行数i和sol.size()相等，若第n-1行无可放位置则i会大于sol.size()
        if(i==0)return true;
        if(sol.size()<i)return false;//（关键步）递归时若第n-1行无可放位置，sol只有n-2行，继续递归无法找到正确解，第n行及以后全部位置不可行，此处负责阻止继续递归
        for(int k=i-1;k>=0;--k){
            if(sol[k][j]=='Q')return false;
            if(j+i-k<n){
                if(sol[k][j+i-k]=='Q')return false;
            }
            if(j-(i-k)>=0){
                if(sol[k][j-(i-k)]=='Q')return false;
            }
        }
        return true;
    }
    void backtrack(vector<vector<string>>&table,string line,vector<string>sol,int n,int start){
        if(start==n){
            table.push_back(sol);
            return;
        }
        for(int i=start;i<n;++i){
            for(int j=0;j<n;++j){
                if(!check(sol,i,j,n))continue;
                else{
                    line=generate(j,n);
                    sol.push_back(line);
                    backtrack(table,line,sol,n,i+1);
                    sol.pop_back();
                }
            }
        }
    }
    
    int totalNQueens(int n) {
        vector<vector<string>>table;
        vector<string>sol;
        string line;
        backtrack(table,line,sol,n,0);
        return table.size();
    }
};
