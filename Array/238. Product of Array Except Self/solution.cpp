class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len=nums.size();
        vector<int> begin(len);
        vector<int> end(len);
        vector<int> res; 
        begin[0]=1;
        end[len-1]=1;
        for(int i=1;i<len;++i){
            begin[i]=begin[i-1]*nums[i-1];
        }
        for(int i=len-2;i>=0;--i){
            end[i]=end[i+1]*nums[i+1];
        }
        for(int i=0;i<len;++i){
            res.push_back(begin[i]*end[i]);
        }
        return res;
    }
};
