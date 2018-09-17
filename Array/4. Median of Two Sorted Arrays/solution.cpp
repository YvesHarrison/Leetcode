class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median,pre,mid=(nums1.size()+nums2.size())/2;
        for(int i=0,j=0;;){
            if(i==nums1.size())median=nums2[j++];
            else if(j==nums2.size())median=nums1[i++];
            else if(nums1[i]<nums2[j])median=nums1[i++];
            else median=nums2[j++];
            if(i+j>mid){
                if((nums1.size()+nums2.size())%2==0)return (median+pre)/2;
                else return median;
            }
            pre=median;
        }
    };
};
