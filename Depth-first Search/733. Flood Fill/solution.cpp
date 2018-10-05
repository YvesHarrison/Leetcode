class Solution {
public:
    void flood(vector<vector<int>>& image, int sr, int sc, int newColor,int color){
        if(image[sr][sc]==color){
            image[sr][sc]=newColor;
            if(sc+1<image[0].size())flood(image,sr,sc+1,newColor,color);
            if(sc-1>=0)flood(image,sr,sc-1,newColor,color);
            if(sr+1<image.size())flood(image,sr+1,sc,newColor,color);
            if(sr-1>=0)flood(image,sr-1,sc,newColor,color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color=image[sr][sc];
        if(image[sr][sc]!=newColor)flood(image, sr, sc, newColor,color);
        return image;
    }
};
