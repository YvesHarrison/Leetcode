class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int len=emails.size();
        vector<string>res;
        for(int i=0;i<len;++i){
            string tmp=emails[i];
            for(int j=0;j<tmp.size();){
                if(tmp[j]=='.'){
                    tmp=tmp.substr(0,j)+tmp.substr(j+1,tmp.size()-1);//tmp.substr(j+1,tmp.size()-1) runs faster than tmp.substr(j+1)
                }
                else if(tmp[j]=='+'){
                    int pos=tmp.find('@');
                    tmp=tmp.substr(0,j)+tmp.substr(pos,tmp.size()-1);//the length>remain length will return remain string as the substring
                    cout<<tmp<<endl;
                    if(find(res.begin(),res.end(),tmp)==res.end())res.push_back(tmp);
                    break;
                }
                else j++;
            }
        }
        
        return res.size();
    }