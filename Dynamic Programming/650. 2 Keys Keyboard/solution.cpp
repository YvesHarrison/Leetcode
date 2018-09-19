class Solution {
public:
    int minSteps(int n) {
        vector<int>res(n+1);
        res[1]=0;
        for(int i=2;i<=n;++i){
            int k=2;
            while(k<=i){
                if(i%k==0){
                    res[i]=res[i/k]+k;
                    break;
                }
                else k++;
            }
        }
        return res[n];
    }
};
