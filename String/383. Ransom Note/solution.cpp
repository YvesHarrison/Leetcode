class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>num(26,0);
        for(int i=0;i<magazine.size();++i){
            num[magazine[i]-'a']++;
        }
        for(int i=0;i<ransomNote.size();++i){
            num[ransomNote[i]-'a']--;
        }
        for(int i=0;i<26;++i){
            if(num[i]<0)return false;
        }
        return true;
    }
};
