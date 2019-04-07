class Solution {
public:
    bool isHappy(int n) {
        int tmp = 0;
        unordered_map<int,int>table;
        while(n != 1){
            while(n > 0){
                tmp += (n % 10) * (n % 10);
                n /= 10;
            }
            n = tmp;
            if(table[tmp] == 1) return false;
            table[tmp] = 1;
            tmp = 0;
        }
        return true;
    }
};
