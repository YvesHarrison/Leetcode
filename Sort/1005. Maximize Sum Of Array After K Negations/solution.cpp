class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        if(A.size()==0)return 0;
        sort(A.begin(),A.end());
        int index = -2;
        for(int i=0;i<A.size();++i){
            if(K==0)break;
            if(A[i]<0){
                A[i] = 0 - A[i];
                K--;
            }
            else if(A[i]==0) break;
            else{
                if(i==0){
                    while(K>0){
                        A[i] = 0 - A[i];
                        K--;
                    }
                }
                if(i>1 &&A[i]>A[i-1]){
                    while(K>0){
                        A[i-1] = 0 - A[i-1];
                        K--;
                    }
                }
                else{
                    while(K>0){
                        A[i] = 0 - A[i];
                        K--;
                    }
                }
            }
        }
        int res=0;
        for(int i=0;i<A.size();++i){
            res+=A[i];
        }
        return res;
    }
};