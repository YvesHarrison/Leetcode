class Solution {
public:
    int find(string a1,string b1){
        int a=(a1[4]-'0')+(a1[3]-'0')*10+(a1[1]-'0')*60+(a1[0]-'0')*600;
        int b=(b1[4]-'0')+(b1[3]-'0')*10+(b1[1]-'0')*60+(b1[0]-'0')*600;
        if(a-b<0){
            if(b-a>720) return 1440-(b-a);
            return b-a;
        }
        else{
            if(a-b>720) return 1440-(a-b);
            return a-b;
        }
    }
    int convert(string a1){
        return (a1[4]-'0')+(a1[3]-'0')*10+(a1[1]-'0')*60+(a1[0]-'0')*600;
    }
    int findMinDifference(vector<string>& timePoints) {
        //sort(timePoints.begin(),timePoints.end());
        int max=721;
        vector<int> time;
        for(int i=0;i<timePoints.size();++i){
            int k=convert(timePoints[i]);
            time.push_back(k);
            time.push_back(k+1440);
        }
        int p;
        sort(time.begin(),time.end());
        for(int i=1;i<time.size();++i){
            p=time[i]-time[i-1];
            if(p<max) max=p;
        }
        return max;
    }
};
