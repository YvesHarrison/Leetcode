class Solution {
public:
//     void backtrack(vector<vector<int>>&res,vector<int>& candidates,vector<int>tmp,int target){
//         if(target==0){
//             res.push_back(tmp);
//         }
        
//         for(int i=0;i<candidates.size();++i){
//             if(candidates[i]>target||(!tmp.empty()&&candidates[i]<tmp.back())) continue;//�������ÿλ��С�����������1��2��2��2��1��2�ظ�
//             tmp.push_back(candidates[i]);
//             backtrack(res,candidates,tmp,target-candidates[i]);
//             tmp.pop_back();
//         }
//     }
    void backtrack(vector<vector<int>>&res,vector<int>& candidates,vector<int>tmp,int target,int position){
        if(target==0){
            res.push_back(tmp);
        }
        
        for(int i=position;i<candidates.size();++i){
            if(candidates[i]>target) continue;//�������ÿλ��С�����������1��2��2��2��1��2�ظ�
            tmp.push_back(candidates[i]);
            backtrack(res,candidates,tmp,target-candidates[i],i);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>tmp;
        //sort(candidates.begin(),candidates.end());
        //backtrack(res,candidates,tmp,target);
        backtrack(res,candidates,tmp,target,0);
        return res;
    }
};
