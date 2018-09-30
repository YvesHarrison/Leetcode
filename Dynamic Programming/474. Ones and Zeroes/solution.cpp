class Solution {
public:
    int cnt1(string a){
        int b=0;
        for(int i=0;i<a.size();++i){
            if(a[i]=='1')b++;
        }
        return b;
    }
    int cnt0(string a){
        int b=0;
        for(int i=0;i<a.size();++i){
            if(a[i]=='0')b++;
        }
        return b;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> bag(m+1,vector<int>(n+1,0));
        for(int i=0;i<strs.size();++i){
            int one=0,zero=0;
            one=cnt1(strs[i]);
            zero=cnt0(strs[i]);
            for(int k=m;k>=zero;k--){
                for(int j=n;j>=one;j--){
                    bag[k][j]=max(bag[k-zero][j-one]+1,bag[k][j]);
                }
            }
        }
        return bag[m][n];
    }
};
