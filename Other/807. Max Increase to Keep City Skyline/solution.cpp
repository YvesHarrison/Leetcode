class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int row_max[r]={0};
        int col_max[c]={0};
        int ma;
        for(int i=0;i<r;++i){
            ma=0;
            for(int j=0;j<c;++j){
                if(grid[i][j]>ma) ma=grid[i][j];
            }
            row_max[i]=ma;
        }
        for(int i=0;i<c;++i){
            ma=0;
            for(int j=0;j<r;++j){
                if(grid[j][i]>ma) ma=grid[j][i];
            }
            col_max[i]=ma;
        }
        int res=0;
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                res+=min(row_max[i],col_max[j])-grid[i][j];
            }
        }
        return res;
    }
};
