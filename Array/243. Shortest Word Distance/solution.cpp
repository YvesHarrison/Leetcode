class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int l1=-1,l2=-1;
        int dis = words.size();
        for(int i=0;i<words.size();++i){
            if(words[i]==word1)l1=i;
            else if(words[i]==word2)l2=i;
            if(l1!=-1&&l2!=-1)dis = min(dis,abs(l1-l2));
        }
        return dis;
    }
};
