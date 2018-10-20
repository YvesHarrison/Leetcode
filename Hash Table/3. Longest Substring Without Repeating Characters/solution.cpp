class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0,i=0,j=0;
        map<char,int>record;
        for(int i=0,j=0;j<s.size();++j){
            if(record[s[j]]!=0){
                i=max(record[s[j]],i);
            }
            res=max(res,j-i+1);
            record[s[j]]=j+1;
        }
        return res;
    }
};

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0,i=0,j=0;
        map<char,int>record;
        while(i<s.size()&&j<s.size()){
            if(record[s[j]]==0){
                res=max(res,j-i+1);
                record[s[j++]]=1;
            }
            else record[s[i++]]=0;
        }
        return res;
    }
};

class Solution3 {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        for(int i=0;i<s.size();++i){
            map<char,int>record;
            int j;
            for(j=i;j<s.size();++j){
                if(record[s[j]]==0)record[s[j]]=1;
                else break;
            }
            res=max(res,j-i);
        }
        return res;
    }
};
