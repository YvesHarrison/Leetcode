class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        if(numRows==0)return res;
        vector<int>tmp;
        tmp.push_back(1);
        res.push_back(tmp);
        if(numRows==1)return res;
        for(int i=2;i<=numRows;++i){
            vector<int>line;
            for(int j=0;j<i;++j){
                if(j==0||j==i-1)line.push_back(1);
                if(j!=0&&j!=i-1) line.push_back(res[i-2][j-1]+res[i-2][j]);//i=3ʵ���ϲ���line��res[2]��line��Ҫ������һ�м�res[1]����������i��Ӧres[i-2]
            }
            res.push_back(line);
        }
        return res;
    }
};
