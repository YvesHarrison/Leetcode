class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>table(grid.size(),vector<int>(grid[0].size(),0));
        table[0][0]=grid[0][0];
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(i==0&&j!=0)table[i][j]=grid[i][j]+table[i][j-1];
                if(i!=0&&j==0)table[i][j]=grid[i][j]+table[i-1][j];
                if(i!=0&&j!=0)table[i][j]=min(grid[i][j]+table[i][j-1],grid[i][j]+table[i-1][j]);
            }
        }
        return table[grid.size()-1][grid[0].size()-1];
    }
};
