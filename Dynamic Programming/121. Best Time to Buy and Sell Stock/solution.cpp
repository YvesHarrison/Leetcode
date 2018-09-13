class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_v=0;
        int min_v=INT_MAX;
        for(int i=0;i<prices.size();++i){//price only has something to do with the minium price before it 
            if(min_v>prices[i]){
                min_v=prices[i];
            }
            if(prices[i]-min_v>max_v){
                max_v=prices[i]-min_v;
            }
        }
        return max_v;
    }
};
