class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.size()==0)return 0;
        if (costs.size()==1)return *min_element(costs[0].begin(),costs[0].end());
        int row=costs.size(),col=costs[0].size();
        for (int i=1;i<row;i++){
            for (int j=0;j<col;j++){
                int temp=costs[i-1][j];
                costs[i-1][j]=INFINITY;
                int use = *min_element(costs[i-1].begin(),costs[i-1].end());
                costs[i-1][j]=temp;
                costs[i][j]+=use;
            }
        }
        return *min_element(costs[row-1].begin(),costs[row-1].end());
    }
};
