class Solution {
public:
    int numberOfArithmeticSlices_math(vector<int>& A) {
        if(A.size()<3)return 0;
        int start,j,res=0;
        for(int i=1;i<A.size()-1;){
            start=i-1;
            int gap=A[i]-A[i-1];
            for(j=i+1;j<A.size();++j){
                if(A[j]-A[j-1]==gap)continue;
                else break;
            }
            if(j-start>=3){
                res+=(j-start-2)*(j-start-1)/2;
            }
            i=j;
        }
        return res;
    }
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()<3)return 0;
        vector<int>dp(A.size(),0);
        int res=0;
        for(int i=2;i<A.size();++i){
            if(A[i]-A[i-1]==A[i-1]-A[i-2]){
                dp[i]=dp[i-1]+1;
                res+=dp[i];
            }
        }
        return res;
    }
};
