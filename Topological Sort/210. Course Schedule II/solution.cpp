class Solution {
public:
    struct node{
        char val='y';
        vector<int>next;
        int income=0;
    };
    int find(vector<node>&graph){
        for(int i=0;i<graph.size();++i){
            if(graph[i].income==0&&graph[i].val=='y')return i;
        }
        return -1;
    }
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<node>graph(numCourses);
        vector<int>res;
        for(int j=0;j<prerequisites.size();++j){
            graph[prerequisites[j].second].next.push_back(prerequisites[j].first);
            graph[prerequisites[j].first].income++;
        }
        vector<int>empty;
        int i=numCourses;
        while(i>=1){
            int index=find(graph);
            if(index==-1)return empty;
            for(int j=0;j<graph[index].next.size();++j){
                graph[graph[index].next[j]].income--;
            }
            graph[index].val='n';
            res.push_back(index);
            i--;
        }
        return res;
    }
};
