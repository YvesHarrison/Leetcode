class NumMatrix {
private: int **dp;
public:
    NumMatrix(vector<vector<int>> matrix) {
        if(matrix.size()==0)return;
        dp = new int*[matrix.size()+1];
        for(int i=0;i<matrix.size()+1;++i) dp[i] = new int[matrix[0].size()+1];
        for(int i=1;i<matrix.size()+1;++i){
            for(int j=1;j<matrix[0].size()+1;++j){
                dp[i][j]=matrix[i-1][j-1]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];//dp[i][j] save the sum of rectangle with upper left corner(0,0) and lower right corner(i-1,j-1)2
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1]+dp[row1][col1]-dp[row2+1][col1]-dp[row1][col2+1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
