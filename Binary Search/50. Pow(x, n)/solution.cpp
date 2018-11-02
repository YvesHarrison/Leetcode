class Solution {
public:
    double myPow(double x, int n) {
        long long pow=n;
        if(pow<0){
            pow=-pow;
            x=1/x;
        }
        double ans=1,cur=x;
        for(long long i=pow;i>0;i/=2){
            if(i%2==1)ans=ans*cur;
            cur=cur*cur;
        }
        return ans;
    }
};//x?n=(x?(n/2))?2=((x?(n/4))?2)?2...=(x)?(2?logn/log2)
