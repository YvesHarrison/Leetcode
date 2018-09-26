class RandomizedSet {

private:
    unordered_set<int>s;
    /** Initialize your data structure here. */
public:
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(s.count(val)==0){
            s.insert(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(s.count(val)!=0){
            s.erase(val);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int n=s.size(); 
        auto it=s.begin();
        advance(it,rand()%n); 
        return *it;
    }
};
