class Solution {
public:
    int maxArea(vector<int>& height) {
        // int len=height.size();
        // int res=0;
        // for(int i=0;i<len-1;++i){
        //     for(int j=i+1;j<len;++j){
        //         if(min(height[i],height[j])*(j-i)>res)res=min(height[i],height[j])*(j-i);
        //     }
        // }O(n^2) 
        int l=0,r=height.size()-1,res=0;
        while(r>l){
            res=max(res,min(height[l],height[r])*(r-l));
            if(height[l]>height[r])r--;
            else l++;
        }
        return res;
    }
};
