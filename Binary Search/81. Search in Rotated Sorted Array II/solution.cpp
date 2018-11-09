class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()==0)return false;
        int left=0,right=nums.size()-1,mid;
        
        while(left<=right){
            while(left<right&&nums[left]==nums[right])left++;
            mid=(left+right)/2;
            if(nums[mid]==target)return true; 
            else if(nums[mid]>=nums[left]){
                if(nums[left]<=target&&nums[mid]>target)right=mid-1;
                else left=mid+1;
            } 
            else if(nums[mid]<=nums[right]){
                if(nums[mid]<target&&nums[right]>=target)left=mid+1;
                else right=mid-1;
            }
        }
        return false;
    }
};
