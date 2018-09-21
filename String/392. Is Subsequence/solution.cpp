class Solution {
public:
    bool isSubsequence(string s, string t) {
        // int len1=s.size();
        // int len2=t.size();
        // int k=0;
        // int j;
        // for(int i=0;i<len1;++i){
        //     for(j=k;j<len2;++j){
        //         if(s[i]==t[j]){
        //             k=j+1;
        //             break;
        //         }
        //     }
        //     if(k!=j+1) return false;
        // }
        // return true;//actually this is a O(m+n) solution beats 98.43%
        int i=0,j=0;
        while(i<s.size()&&j<t.size()){
            if(t[j++]==s[i])i++;}
        return i==s.size();//O(m+n)beats 86.56%
    }
};
