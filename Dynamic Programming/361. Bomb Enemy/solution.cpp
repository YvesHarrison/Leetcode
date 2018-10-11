class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int row=grid.size();
        if(row==0)return 0;
        int col=grid[0].size();
        if(col==0)return 0;
        vector<vector<pair<int,int>>>dp(row,vector<pair<int,int>>(col,make_pair<int,int>(0,0)));
        for(int i=0;i<row;++i){
            int kill=0;
            queue<int>zero;
            for(int j=0;j<col;++j){
                if(grid[i][j]=='0')zero.push(j);
                else if(grid[i][j]=='E')kill++;
                if(grid[i][j]=='W'||j==col-1){//using else if(grid[i][j]=='W'||j==col-1) the condition only consider grid[i][j]=='W' and ignore j==col-1
                    while(!zero.empty()){
                        int k=zero.front();
                        dp[i][k].first=kill;
                        zero.pop();
                    }
                    kill=0;
                }
            }
        }
        int res=0;
        for(int i=0;i<col;++i){
            int kill=0;
            queue<int>zero;
            for(int j=0;j<row;++j){
                if(grid[j][i]=='0')zero.push(j);
                else if(grid[j][i]=='E')kill++;
                if(grid[j][i]=='W'||j==row-1){
                    while(!zero.empty()){
                        int k=zero.front();
                        dp[k][i].second=kill;
                        res=max(res,dp[k][i].first+dp[k][i].second);
                        zero.pop();
                    }
                    kill=0;
                }
                
            }
        }
        // for(int i=0;i<row;++i){
        //     for(int j=0;j<col;++j){
        //         cout<<'('<<dp[i][j].first<<','<<dp[i][j].second<<')';
        //     }
        //     cout<<endl;
        // }
        return res;
    }
};
