class Solution {
public:
    string intToRoman(int num) {
        int div[]={1000,500,100,50,10,5,1};
        int div1[]={900,400,90,40,9,4,0};
        char tag[]={'M','D','C','L','X','V','I'};
        string res="";
        int pos;
        for(int i=0;i<7;++i){
            while(num>=div1[i]&&num>0){
                pos = num/div[i];
                if(!pos){
                    if(i%2==0) res=res+tag[i+2]+tag[i];
                    else res=res+tag[i+1]+tag[i];
                    num%=div1[i];
                }
                else{
                    res+=tag[i];
                    num-=div[i];
                }
            }
        }
        return res;
    }
};
