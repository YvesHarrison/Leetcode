class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(n+1);
        res[1]=1;
        int i=1;
        int j=1;
        int k=1;
        for(int m=2;m<=n;++m){
            res[m]=min(res[i] * 2, min(res[j] * 3, res[k] * 5));
            if (res[m] == res[i] * 2) i++;
            if (res[m] == res[j] * 3) j++;
            if (res[m]== res[k] * 5) k++;
        }
        return res[n];
    }
};
