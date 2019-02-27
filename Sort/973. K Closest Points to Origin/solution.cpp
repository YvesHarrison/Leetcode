class Solution {
public:
    static bool cmp(vector<int> a,vector<int>b){
        return a[1]*a[1]+a[0]*a[0]<b[1]*b[1]+b[0]*b[0];
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(),points.end(),cmp);
        vector<vector<int>>re;
        for(int i=0;i<K;++i){
            re.push_back(points[i]);
        }
        return re;
    }
};
