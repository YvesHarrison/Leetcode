class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int> >table(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),0)); 
        if(obstacleGrid[0][0]==0)table[0][0]=1;
        else table[0][0]=0;
        for(int i=0;i<obstacleGrid.size();++i){
            for(int j=0;j<obstacleGrid[0].size();++j){
                if(i==0&&j>0){
                    if(obstacleGrid[i][j]==0)table[i][j]=table[i][j-1];
                    else table[i][j]=0;
                }
                if(j==0&&i>0){
                    if(obstacleGrid[i][j]==0)table[i][j]=table[i-1][j];
                    else table[i][j]=0;
                }
                if(i>0&&j>0){
                    if(obstacleGrid[i][j]==0)table[i][j]=table[i-1][j]+table[i][j-1];
                    else table[i][j]=0;
                } 
            }
        }
        return table[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};
