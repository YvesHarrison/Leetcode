class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>res;
        res.push_back(1);
        if(rowIndex==0)return res;
        for(int i=1;i<=rowIndex;++i){
            vector<int>line;
            for(int j=0;j<=i;++j){
                if(j==0||j==i)line.push_back(1);
                if(j!=0&&j!=i) line.push_back(res[j-1]+res[j]);
            }
            res=line;
        }
        return res;
    }
};
