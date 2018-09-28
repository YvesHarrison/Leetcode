class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(minstack.size()==0){
             minstack.push_back(x);
             minloc.push_back(x);
        }
        else{
            minstack.push_back(x);
            if(x<minloc.back())minloc.push_back(x);
            else minloc.push_back(minloc.back());
        }
    }
    
    void pop() {
        minstack.pop_back();
        minloc.pop_back();
    }
    
    int top() {
        return minstack.back();
    }
    
    int getMin() {
        return minloc.back();
    }
private:
    vector<int>minstack;
    vector<int>minloc;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
