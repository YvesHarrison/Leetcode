class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int len1=A.size();
        int len2=A[0].size();
        for(int i=0;i<len1;++i){
            for(int j=0;j<len2/2;++j){
                swap(A[i][j],A[i][len2-1-j]);
            }
        }
        for(int i=0;i<len1;++i){
            for(int j=0;j<len2;++j){
                if(A[i][j]==1) A[i][j]=0;
                else A[i][j]=1;
            }
        }
        return A;
    }
};
