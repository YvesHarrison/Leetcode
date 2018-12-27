class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int len=emails.size();
        map<string,int>res;
        for(int i=0;i<len;++i){
            string tmp=emails[i];
            for(int j=0;j<tmp.size();){
                if(tmp[j]=='.'){
                    tmp=tmp.substr(0,j)+tmp.substr(j+1,tmp.size()-1);
                }
                else if(tmp[j]=='+'){
                    int pos=tmp.find('@');
                    tmp=tmp.substr(0,j)+tmp.substr(pos,tmp.size()-1);
                    res[tmp]++;
                    break;
                }
                else if(tmp[j]=='@'){
                    res[tmp]++;
                    break;
                }
                else j++;
            }   
        }
        return res.size();
    }
};