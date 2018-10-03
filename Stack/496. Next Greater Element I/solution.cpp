class Solution {
public:
    // vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    //     int j;bool fin;vector<int> res;
    //     for(int i=0;i<findNums.size();++i){
    //         for(int k=0;k<nums.size();++k){
    //             if(nums[k]==findNums[i]){
    //                 j=k;break;
    //             } 
    //         }
    //         fin=false;
    //         for(int k=j+1;k<nums.size();++k){
    //             if(nums[k]>findNums[i]){
    //                 res.push_back(nums[k]);fin=true;break;
    //             } 
    //         }
    //         if(!fin) res.push_back(-1);
    //     }
    //     return res;
    // }
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int>res;
        stack<int>q;
        map<int,int>hashmap;
        int k;
        for(int i=0;i<nums.size();++i){
            while(!q.empty()&&nums[i]>q.top()){
                k=q.top();
                q.pop();
                hashmap[k]=nums[i];
            }
            q.push(nums[i]);
        }
        while(!q.empty()){
            k=q.top();
            q.pop();
            hashmap[k]=-1;
        }
        for(int i=0;i<findNums.size();++i)res.push_back(hashmap[findNums[i]]);
        return res;
    }
};
