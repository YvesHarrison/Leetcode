class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        if(nums[0]<nums[nums.size()-1])return nums[0];
        int right=nums.size()-1,left=0,mid;
        while(left<right){
            if(nums[left]<nums[right])return nums[left];
            mid=(left+right)/2;
            if(nums[mid]>nums[mid+1]&&mid+1<=nums.size()-1)return nums[mid+1];
            if(nums[mid-1]>nums[mid]&&mid-1>=0)return nums[mid];
            if(nums[mid]<nums[left])right=mid-1;
            else if(nums[mid]>nums[right])left=mid+1;
            else left++;
        }
        return nums[left];
    }
};
