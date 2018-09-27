class Solution {
public:
    int trap(vector<int>& height) {
        // if(height.size()==0)return 0;
        // int len=height.size();
        // vector<int>left_max(len),right_max(len);
        // left_max[0]=height[0];
        // for(int i=1;i<len;++i){
        //     left_max[i]=max(left_max[i-1],height[i]);
        // }
        // right_max[len-1]=height[len-1];
        // for(int i=len-2;i>=0;--i){
        //     right_max[i]=max(right_max[i+1],height[i]);
        // }
        // int res=0;
        // for(int i=0;i<len;++i){
        //     res+=(min(left_max[i],right_max[i])-height[i]);
        // }
        // return res;//dp
        stack<int>tra;
        int res=0,len=0;
        for(int i=0;i<height.size();++i){
            while(!tra.empty()&&height[tra.top()]<height[i]){
                int top=tra.top();
                tra.pop();
                if(tra.empty())break;
                res+=(i-tra.top()-1)*(min(height[i],height[tra.top()])-height[top]);
            }
            tra.push(i);    
        }//stack
        return res;
    }
};
