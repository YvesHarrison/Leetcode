class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int res = 1,j;
        for(int i = 0; i < nums.size() - 1; ){
            int tmp = 1;
            for(j = i + 1; j < nums.size(); ++j){
                if(nums[j] > nums[j - 1]) tmp++;
                else break;
            }
            if(tmp > res) res = tmp;
            i = j;
        }
        return res;
    }
};
