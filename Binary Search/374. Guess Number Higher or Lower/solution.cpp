// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int start=1,end=n;
        while(end>=start){
            int mid=(start-end)/2+end;//start+end out of range in some test cases
            int k=guess(mid);
            if(k==-1)end=mid-1;
            else if(k==1)start=mid+1;
            else return mid;
        }
        return -1;
    }
};
