class Solution {
public:
    int dis(vector<int>& p1, vector<int>& p2){
        return (p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        map<int,int>length;
        length[dis(p1,p2)]++;
        length[dis(p1,p3)]++;
        length[dis(p1,p4)]++;
        length[dis(p2,p3)]++;
        length[dis(p2,p4)]++;
        length[dis(p3,p4)]++;
        return !length.count(0) and length.size()==2;
    }
};
