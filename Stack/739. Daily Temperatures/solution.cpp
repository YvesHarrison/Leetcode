class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> tem;
        vector<int>res(temperatures.size(),0);
        for(int i=0;i<temperatures.size();++i){
            if(!tem.empty()){
                pair<int,int> temp=tem.top();
                while(temperatures[i]>temp.first&&!tem.empty()){
                    res[temp.second]=i-temp.second;
                    tem.pop();
                    if(!tem.empty())temp=tem.top();
                }
                tem.push(make_pair(temperatures[i],i));
            }
            else tem.push(make_pair(temperatures[i],i));
        }
        return res;
    }
};
