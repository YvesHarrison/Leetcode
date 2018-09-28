class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>alp(26,0);
        vector<char>letter;
        for(auto &ch : s){
            alp[ch-'a']++;
        }
        for(auto &ch : s){
            alp[ch-'a']--;
            if(find(letter.begin(),letter.end(),ch)==letter.end()){
                while(!letter.empty()&&letter.back()>ch&&alp[letter.back()-'a']!=0)letter.pop_back();
                letter.push_back(ch);
            }
        }
        string res="";
        for(int i=0;i<letter.size();++i){
            res+=letter[i];
        }
        return res;
    }
};
