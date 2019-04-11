class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char>res;
        if(chars.size() == 1)return 1;
        for(int i = 0; i < chars.size() - 1; ){
            int cnt = 0;
            int j;
            for(j = i; j < chars.size(); ++j){
                if(chars[j] != chars[i])break;
                if(chars[j] == chars[i]){
                    cnt++;
                    if(j == chars.size() - 1)break;
                } 
            }
            
            if(cnt == 1)res.push_back(chars[i]);
            else{
                string tmp = "";
                res.push_back(chars[i]);
                while(cnt > 0){
                    tmp += (cnt%10 + '0');
                    cnt = cnt / 10;
                }
                for(int k = tmp.size() - 1; k >= 0; --k){
                    res.push_back(tmp[k]);
                }
            }
            i = j;
        }
        if(chars[chars.size() - 1] != chars[chars.size() - 2])res.push_back(chars[chars.size() - 1]);
        chars = res;
        return res.size();
    }
};
