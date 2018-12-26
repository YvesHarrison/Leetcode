class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int len=flowers.size();
        int res=-1;
        if(len==0||k>=len)return res;
        k++;
        int buckets=(len+k-1)/k;
        vector<int>left(buckets,INT_MAX);
        vector<int>right(buckets,INT_MIN);
        for(int i=0;i<flowers.size();++i){
            int index=flowers[i];
            int pos=index/k;
            if(index<left[pos]){
                left[pos]=index;
                if(pos>0&&right[pos-1]==index-k)return i+1;
            }
            if(index>right[pos]){
                right[pos]=index;
                if(pos<buckets-1&&left[pos+1]==index+k)return i+1;
            }
        }
        return res;
    }
};