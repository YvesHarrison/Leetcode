class Solution {
public:
    void backtrack(int & cnt,int N,vector<int>tmp){
        if(tmp.size()==N){
            cnt++;
            return;
        }
        
        for(int i=1;i<=N;++i){
            if((i%(tmp.size()+1)==0||(tmp.size()+1)%i==0)&&find(tmp.begin(),tmp.end(),i)==tmp.end()){
                 //固定插入位置 tmp.size()找i，而非固定i寻找j到N的插入位置，减少一层循环 
				tmp.push_back(i);
                backtrack(cnt,N,tmp);
                tmp.pop_back();
            }
            
        }
        return;
    }
    int countArrangement(int N) {
        int cnt=0;
        vector<int>tmp;
        backtrack(cnt,N,tmp);
        return cnt;
    }
};
