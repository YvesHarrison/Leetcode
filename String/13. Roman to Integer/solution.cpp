class Solution {
public:
    int cmp(const pair<char,int>&x,const pair<char,int>&y){
        return x.second>y.second;
    }
    string reorganizeString(string S) {
        string ss = "";
        priority_queue<pair<int,char>> q;
        int freq[26] = {0};
        for(int i = 0;i < S.size();i++){
            freq[S[i]-'a']++;
        }
        for(int i = 0;i < 26;i++)
            if(freq[i] > 0)
                q.push(make_pair(freq[i],'a'+i));
        pair<int,char> pr,p;
        while(!q.empty()){
            pr = q.top();q.pop();
            ss+=pr.second;
            if(q.size()){
                p = q.top();q.pop();
                ss+=p.second;
                pr.first--;
                p.first--;
                if(pr.first)
                    q.push(pr);
                if(p.first)
                    q.push(p);
            }else{
                if(ss.size() < S.size())
                    return "";
                else
                    break;
            }
        }
        return ss;
    }
};
