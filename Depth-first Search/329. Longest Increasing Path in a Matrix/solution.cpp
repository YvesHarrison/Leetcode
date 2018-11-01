class Solution {
public:
    int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};//[1,0],[-1,0],[0,1],[0,-1]];
    int find(vector<vector<int>>& matrix,int i,int j,int row,int col,vector<vector<int>>&save){
        if(save[i][j]!=0)return save[i][j];
        for(int k=0;k<4;++k){
            int x=i+dirs[k][0];
            int y=j+dirs[k][1];
            if(x>=0&&y>=0&&x<row&&y<col&&matrix[i][j]<matrix[x][y]){
                save[i][j]=max(save[i][j],find(matrix,x,y,row,col,save));
            }
        }
        return ++save[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res=0;
        int row=matrix.size();
        if(row==0)return 0;
        int col=matrix[0].size();
        vector<vector<int>>save(row,vector<int>(col,0));
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                res=max(res,find(matrix,i,j,row,col,save));
                cout<<res<<endl;;
            }
        }
        return res;
    }
};
