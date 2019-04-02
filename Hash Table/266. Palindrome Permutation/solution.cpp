class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int>table(128,0);
        for(int i=0;i<s.size();++i){
            table[int(s[i])]++;
        }
        int cnt=0;
        for(int i=0;i<128;++i){
            if(table[i]%2==1)cnt++;
        }
        return cnt<=1;
    }
};
