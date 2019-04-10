class Solution {
public:
    bool isStrobogrammatic(string num) {
        int len = num.size();
        if(len % 2 == 1 && num[len / 2] != '8' && num[len / 2] != '1' && num[len / 2] != '0') return false;
        for(int i = 0; i < len / 2; ++i){
            if(num[i] == '0' && num[len - i - 1] == '0') continue;
            else if(num[i] == '1' && num[len - i - 1] == '1') continue;
            else if(num[i] == '8' && num[len - i - 1] == '8') continue;
            else if(num[i] == '6' && num[len - i - 1] == '9') continue;
            else if(num[i] == '9' && num[len - i - 1] == '6') continue;
            else return false;
        }
        return true;
    }
};
