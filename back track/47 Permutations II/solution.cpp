class Solution {
public:
    // void backtracking(vector<vector<int>>&res,vector<int>& nums,vector<int>tmp,int size){
    //     if(tmp.size()==size and find(res.begin(),res.end(),tmp)==res.end()){
    //         res.push_back(tmp);//��ȥ�ظ�
    //     }
    //     else{
    //         vector<int>remain;
    //         for(int i=0;i<nums.size();++i){
    //             remain=nums;
    //             tmp.push_back(nums[i]);
    //             remain.erase(remain.begin()+i);//��δ��ѡ��Ľ���ݹ�����ظ�,
    //             backtracking(res,remain,tmp,size);
    //             tmp.pop_back();
    //         }
    //     }
    // }̫��
    void backtracking(vector<vector<int>>&res,vector<int>& nums,vector<int>&tmp, vector<bool>use){
        if(tmp.size()==nums.size()){
            res.push_back(tmp);
            return;
        }
        else{
            for(int i=0;i<nums.size();++i){
                if(use[i]||(i>0 && nums[i]==nums[i-1] && !use[i-1])){
                    continue;
                }
                tmp.push_back(nums[i]);
                use[i]=true;
                backtracking(res,nums,tmp,use);
                use[i]=false;
                tmp.pop_back();
                
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>tmp;
        vector<bool>use(nums.size());
        sort(nums.begin(),nums.end());
        backtracking(res,nums,tmp,use);
        return res;
    }
};
