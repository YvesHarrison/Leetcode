class Solution {
public:
    int romanToInt(string s) {
        char tag[]={'M','D','C','L','X','V','I'};
        int div[]={1000,500,100,50,10,5,1};
        int div1[]={900,400,90,40,9,4,0};
        int res=0;
        int j=0;
        for(int i=0;i<7&&j<s.size();++i){
            if(i!=0&&tag[i]==s[j]&&tag[i-1]==s[j+1]){
                res+=div1[i-1];
                j+=2;
            }
            else if((i!=0&&i!=1)&&tag[i]==s[j]&&tag[i-2]==s[j+1]){
                res+=div1[i-2];
                j+=2;
            }
            else if(tag[i]==s[j]){
                while(j<s.size()&&tag[i]==s[j]){
                    res+=div[i];
                    j++;
                }
            }
        }
        return res;
    }
};
