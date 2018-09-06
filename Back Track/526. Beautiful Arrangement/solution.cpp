class Solution {
public:
    void backtrack(int & cnt,int N,vector<int>tmp){
        if(tmp.size()==N){
            cnt++;
            return;
        }
        
        for(int i=1;i<=N;++i){
            if((i%(tmp.size()+1)==0||(tmp.size()+1)%i==0)&&find(tmp.begin(),tmp.end(),i)==tmp.end()){
                 //�̶�����λ�� tmp.size()��i�����ǹ̶�iѰ��j��N�Ĳ���λ�ã�����һ��ѭ�� 
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
