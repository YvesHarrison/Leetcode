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
    bool check(vector<string>&sol,int i,int j,int n){//iΪ�����кţ��������е�sol�ж����еķ���λ���Ƿ���У���֤���ɵ�����i��sol.size()��ȣ�����n-1���޿ɷ�λ����i�����sol.size()
        if(i==0)return true;
        if(sol.size()<i)return false;//���ؼ������ݹ�ʱ����n-1���޿ɷ�λ�ã�solֻ��n-2�У������ݹ��޷��ҵ���ȷ�⣬��n�м��Ժ�ȫ��λ�ò����У��˴�������ֹ�����ݹ�
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
