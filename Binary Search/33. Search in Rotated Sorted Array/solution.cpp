class Solution {
public:
    int findMin(vector<int>& nums) {
         if(nums.size()==1)return 0;
         if(nums[0]<nums[nums.size()-1]) return 0;
         int right=nums.size()-1,left=0,mid;
         while(left<=right){
             mid=(left+right)/2;
             if(nums[mid]>nums[mid+1])return mid+1;
             if(nums[mid-1]>nums[mid])return mid;
             if(nums[mid]>nums[0])left=mid+1;
             else right=mid-1;
         }
     }
    int binary_search(vector<int>& nums,int target,int left, int right){
        int mid;
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]==target)return mid;
            if(nums[mid]<target)left=mid+1;
            else right=mid-1; 
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)return -1;
        int start=findMin(nums);
        
        if(target<=nums[nums.size()-1])return binary_search(nums,target,start,nums.size()-1);
        else return binary_search(nums,target,0,start);
    }
    
    int search_(vector<int>& nums, int target) {
      if(nums.size()==0)return -1;
        int left=0,right=nums.size()-1,mid;
        
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]==target)return mid; 
            else if(nums[mid]>=nums[left]){
                if(nums[left]<=target&&nums[mid]>target)right=mid-1;
                else left=mid+1;
            } 
            else if(nums[mid]<=nums[right]){
                if(nums[mid]<target&&nums[right]>=target)left=mid+1;
                else right=mid-1;
            }
        }
        return -1;
    }
};
