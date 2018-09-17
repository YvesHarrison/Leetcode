class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0||(x%10==0&&x!=0))return false;
        if(x<10)return true;
        int new_num=0;
        while(x>new_num){
            new_num=new_num*10+x%10;
            x/=10;
        }
        return x==new_num||x==new_num/10;
    }
};
