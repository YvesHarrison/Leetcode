class Solution {
public:
    string addBinary(string a, string b) {
        string res="";
        int len1=a.size()-1,len2=b.size()-1;
        int c=0;
        while(len1>=0||len2>=0||c==1){
            if(len1>=0){
               c+=a[len1--]-'0'; 
            }
            else c+=0;
            if(len2>=0){
               c+=b[len2--]-'0'; 
            }
            else c+=0;
            res=char(c%2+'0')+res;
            c/=2;
        }
        return res;
    }
};
