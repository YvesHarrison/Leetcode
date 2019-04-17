class Solution {
public:
    int mySqrt(int x) {
        if(x==0)return 0;
        long start = 1,end = x;
        long mid;
        while(start<=end){
            mid = (start + end) / 2;
            if(mid * mid <= x && (mid + 1) * (mid + 1) > x) return mid;
            else if(mid * mid >x) end = mid -1;
            else start = mid + 1;
        }
        return 0;
    }
};
