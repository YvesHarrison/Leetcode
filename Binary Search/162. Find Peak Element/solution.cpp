class Solution_MIN {
public:
    int findPeakElement(vector<int>& nums) {
        int low=1,high= nums.size(),mid;
        int d=INT_MIN;nums.push_back(d);nums.insert(nums.begin(),d);//meet problem when vector contains INT_MIN in the front or end
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1])return mid-1;
            if(nums[mid]>nums[mid+1]&&nums[mid]<nums[mid-1])high=mid-1;
            else if(nums[mid]<nums[mid+1]&&nums[mid]>nums[mid-1])low=mid+1;
            else high=mid-1;
        }
    
        return low-1;
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0,high= nums.size()-1,mid;
        while(low<high){
            mid=(low+high)/2;
            if(nums[mid]>nums[mid+1])high=mid;
            else low=mid+1;
        }
        return low;
    }
};
