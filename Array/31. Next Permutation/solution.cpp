class Solution {
public: 
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1||nums.size()==0)return;
        for(int i=nums.size()-1;i>=1;--i){
            if(nums[i-1]<nums[i]){//can not get a larger number by swaping digits in a increasing subsequence so find the digit ends increasing subsequence, and swap it with a smallest value bigger it in the increasing sequence. The sequence remains increasing then reverse it making it decreasing(this is the smallest). Then numbers are lexicographically next greater permutation of numbers.
                for(int j=nums.size()-1;j>=i;--j){
                    if(nums[j]>nums[i-1]){
                        swap(nums[j],nums[i-1]);
                        reverse(nums.begin()+i,nums.end());
                        return;
                    }
                }
            }
        }
        reverse(nums.begin(),nums.end());
    }
};
