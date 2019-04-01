class Solution {
public:
    int fib(int N) {
        if(N==0)return 0;
        if(N==1)return 1;
        vector<int>table;
        table.push_back(0);
        table.push_back(1);
        for(int i=2;i<=N;++i){
            table.push_back(table[i-1]+table[i-2]);
        }
        return table[N];
    }
};
