class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int>pos(nums.size());
        vector<int>neg(nums.size());
        pos[0]=nums[0];
        neg[0]=nums[0];
        int product=nums[0];
        for(int i=1;i<nums.size();++i){
            pos[i]=max(nums[i],max(pos[i-1]*nums[i],neg[i-1]*nums[i]));
            neg[i]=min(nums[i],min(pos[i-1]*nums[i],neg[i-1]*nums[i]));
            product=max(pos[i],product);
        }
        return product;
    }
};
