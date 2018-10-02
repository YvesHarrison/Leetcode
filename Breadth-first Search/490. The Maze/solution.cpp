class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<pair<int,int>>table;
        vector<vector<bool>> visit(maze.size(),vector<bool>(maze[0].size(),false));
        int vertical[4]={1,-1,0,0};
        int horizontal[4]={0,0,1,-1};
        table.push_back(make_pair(start[0],start[1]));
        visit[start[0]][start[1]]=true;
        while(!table.empty()){
            pair<int,int>tmp=table.front();
            table.erase(table.begin());
            if(tmp.first==destination[0]&&tmp.second==destination[1])return true;
            for(int i=0;i<4;++i){
                int x=tmp.second+horizontal[i];
                int y=tmp.first+vertical[i];
                while(y>=0&&y<maze.size()&&x>=0&&x<maze[0].size()&&maze[y][x]==0){
                    x+=horizontal[i];
                    y+=vertical[i];
                }
                if(!visit[y-vertical[i]][x-horizontal[i]]){
                    table.push_back(make_pair(y-vertical[i],x-horizontal[i]));
                    visit[y-vertical[i]][x-horizontal[i]]=true;
                }
            }
        }
        return false;
    }
};
