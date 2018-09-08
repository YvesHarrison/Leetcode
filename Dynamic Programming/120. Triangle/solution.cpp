class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==0)return 0;
        if(triangle.size()==1)return triangle[0][0];
        for(int i=1;i<triangle.size();++i){
            triangle[i][0]+=triangle[i-1][0];
            triangle[i][triangle[i].size()-1]+=triangle[i-1][triangle[i-1].size()-1];
            for(int j=1;j<i;++j){
                triangle[i][j]+=min(triangle[i-1][j],triangle[i-1][j-1]);
            }
        }
        int ma=0x7fffffff;
        for(int i=0;i<triangle.size();++i){
            ma=min(ma,triangle[triangle.size()-1][i]);
        }
        return ma;
    }
};
