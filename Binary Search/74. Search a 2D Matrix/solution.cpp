class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size()-1;
        if(row==-1)return false;
        int col=matrix[0].size()-1;
        if(col==-1)return false;
        for(int i=0;i<=row;++i){
            if(target>=matrix[i][0]&&target<=matrix[i][col]){
                int start=0,end=col;
                while(start<=end){
                    int mid=(start+end)/2;
                    if(matrix[i][mid]>target)end=mid-1;
                    else if(matrix[i][mid]<target)start=mid+1;
                    else return true;
                }
                return false;
            }
        }
        return false;
    }
};
