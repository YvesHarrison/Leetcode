class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        map<int,int> rec;
        vector<int>res(n+1);
        res[1]=1;
        for(int i=0;i<primes.size();++i){
            rec[primes[i]]=1;
        }
        for(int i=2;i<=n;++i){
            int big=0x7fffffff;
            for(int j=0;j<primes.size();++j){
                if(big>res[rec[primes[j]]]*primes[j]) big=res[rec[primes[j]]]*primes[j];
            }
            res[i]=big;
            for(int j=0;j<primes.size();++j){
                if(big==res[rec[primes[j]]]*primes[j])rec[primes[j]]++;
            }
        }
        return res[n];
    }
};
