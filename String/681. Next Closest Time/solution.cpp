class Solution {
public:
    string nextClosestTime(string time) {
        int res=0;
        res=time[4]-'0'+(time[3]-'0')*10+(time[1]-'0')*60+(time[0]-'0')*600;
        vector<int> table;
        for(int i=0;i<time.size();++i){
            if(time[i]!=':')table.push_back(time[i]-'0');
        }
        while(true){
            res=(res+1)%1440;
            vector<int>digit;
            digit.push_back(res/600);digit.push_back(res/60%10);digit.push_back(res%60/10);digit.push_back(res%10);
            bool flag=true;
            for(int i=0;i<digit.size();++i){
                if(find(table.begin(),table.end(),digit[i])==table.end()){
                    flag=false;
                    break;
                }
            }
            if(flag){
                string tmp="";
                tmp+=digit[0]+'0';tmp+=digit[1]+'0';tmp+=':';tmp+=digit[2]+'0';tmp+=digit[3]+'0';
                return tmp;
            }
        }
    }
};
