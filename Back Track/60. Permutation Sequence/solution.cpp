class Solution {
public:
    // void backtrack(vector<vector<int>>&table,vector<int>&tmp,int n){
    //     if(tmp.size()==n){
    //         table.push_back(tmp);
    //         return;
    //     }
    //     for(int i=1;i<=n;++i){
    //         if(find(tmp.begin(),tmp.end(),i)!=tmp.end())continue;
    //         tmp.push_back(i);
    //         backtrack(table,tmp,n);
    //         tmp.pop_back();
    //     }
    // }
    string getPermutation(int n, int k) {
        // vector<vector<int>>table;
        // vector<int>tmp;
        // backtrack(table,tmp,n);
        // string res="";
        // for(int i=0;i<n;++i){
        //     res+=(table[k-1][i]+'0');
        // }
        // return res;backtracking result in time limit exceeded
        vector<int>nums;
        string ans;
        for(int i=1;i<=n;++i){
            nums.push_back(i);
        }
        int quo,rem;
        while(n>1){
            int factor=1;
            for(int i=1;i<=n-1;++i)factor*=i;
            quo=k/factor;
            rem=k%factor;
            if(rem==0){
                k=factor;
                quo--;
            }
            else k=rem;
            ans+=nums[quo]+'0';
            nums.erase(nums.begin()+quo);
            n--;
        }
        ans+=nums[0]+'0';
        return ans;
    }
};
