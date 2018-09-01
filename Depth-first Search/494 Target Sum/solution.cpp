class Solution {
public:
    void find(vector<int>& nums, int S,int pos,int &cnt){
        if(pos==nums.size()){
            if(S==0)cnt++;
        } 
       else{
           find(nums,S+nums[pos],pos+1,cnt);
           find(nums,S-nums[pos],pos+1,cnt);
       }
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int cnt=0;
        find(nums,S,0,cnt);
        return cnt;
    }
};
