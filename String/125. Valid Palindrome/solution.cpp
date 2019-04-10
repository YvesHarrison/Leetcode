class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string tmp = "";
        for(int i = 0; i < s.size(); ++i){
            if(s[i] - 'a'>= 0 && s[i] - 'a' < 26) tmp += s[i];
            else if(s[i] - '0'>= 0 && s[i] - '0' < 10)tmp += s[i];//number
        }
        for(int i = 0; i < tmp.size() / 2; ++i){
            if(tmp[i] != tmp[tmp.size() - i - 1]) return false;
        }
        return true;
    }
};
