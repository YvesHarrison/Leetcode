class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int start = 0;
        int end = A.size()-1,mid;
        while(start<=end){
            mid = (start+end)/2;
            if(A[mid]>A[mid+1]&&A[mid]>A[mid-1])return mid;
            else if(A[mid]<A[mid+1])start=mid+1;
            else if(A[mid]<A[mid-1])end=mid-1;
        }
        return mid;
    }
};
