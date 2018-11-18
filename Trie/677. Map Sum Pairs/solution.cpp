class MapSum {
public:
    /** Initialize your data structure here. */
    struct node{
        int val;
        node *son[26];
        node():val(0){for(int i=0;i<26;i++) son[i]=NULL;}
    };
    
    node *root;
    MapSum() {
        root=new node;
    }
    
    void insert(string key, int val) {
        node *tmp=root;int index;
        for(int i=0;i<key.size();++i){
            index=key[i]-'a';
            if(tmp->son[index]==NULL) tmp->son[index]=new node();
            tmp=tmp->son[index];
        }
        int record=0;
        for(int i=0;i<26;++i){
            if(tmp->son[i]!=NULL)record+=tmp->son[i]->val;
        }
        record=val-(tmp->val-record);
        node *tmp1=root;
        for(int i=0;i<key.size();++i){
            index=key[i]-'a';
            tmp1=tmp1->son[index];
            tmp1->val+=record;
        }
    }
    
    int sum(string prefix) {
        node *tmp=root;
        for(int i=0;i<prefix.size();++i){
            if(tmp==NULL)break;
            tmp=tmp->son[prefix[i]-'a'];
        }
        return tmp?tmp->val:0;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
