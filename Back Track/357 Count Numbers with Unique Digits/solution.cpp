class Solution {
public:
    int math(int n){
        int res,tmp;
        if(n==0)return 1;
        if(n==1)res=10;
        else{
            res=10;
            for(int i=2;i<=n;++i){
                int tmp=9;
                for(int j=2;j<=i;++j){
                    tmp*=(9-j+2);
                }
                res+=tmp;
            }
        }
        return res;
    }
    
    int cnt=0;
    bool visit[12];
    
    void backtrack(int step,int n,bool zero){
        if(step==n)cnt++;
        else{
            for(int i=0;i<=9;++i){
                if(i!=0)zero=false;
                if(!visit[i]||zero){
                    visit[i]=true;
                    backtrack(step+1,n,zero);
                    visit[i]=false;
                }
            }
        }
    }
    int countNumbersWithUniqueDigits(int n) {
        backtrack(0,n,true);
        return cnt;
    }
};
