class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> >table(m,vector<int>(n,0)); 
        table[0][0]=1;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(i==0&&j>0)table[i][j]=table[i][j-1];
                if(j==0&&i>0)table[i][j]=table[i-1][j];
                if(i>0&&j>0) table[i][j]=table[i-1][j]+table[i][j-1];
            }
        }
        return table[m-1][n-1];
    }
};
