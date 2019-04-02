class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>letter(26,0);
        if(s.size()!=t.size())return false;
        for(int i=0;i<s.size();++i){
            letter[s[i]-'a']++;
            letter[t[i]-'a']--;
        }
        return count(letter.begin(),letter.end(),0)==26;
    }
};
