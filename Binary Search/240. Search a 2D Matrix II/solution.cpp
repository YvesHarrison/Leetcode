class Solution {
public:
    bool search(vector<vector<int>>& matrix, int target,int start,bool v){
        int low=start,high;
        if(v) high=matrix[0].size()-1;
        else high=matrix.size()-1;
    
        while(high>=low){
            int mid=(high+low)/2;
            if(v){
                if(matrix[start][mid] < target)low = mid + 1;
                else if(matrix[start][mid] > target)high = mid - 1;
                else return true;
            }
            else{
                if(matrix[mid][start] < target)low = mid + 1;
                else if(matrix[mid][start] > target)high = mid - 1;
                else return true;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // int row=matrix.size()-1;
        // int col=0;
        // while(row>=0&&col<matrix[0].size()){
        //     if(matrix[row][col]>target) row--;
        //     else if(matrix[row][col]<target)col++;
        //     else return true;
        // }
        // return false;
        if(matrix.size()==0)return false;
        for(int i=0;i<min(matrix[0].size(),matrix.size());++i){
            bool a=search(matrix,target,i,true);
            bool b=search(matrix,target,i,false);
            if(a||b)return true;
        }
        return false;
    }
};
