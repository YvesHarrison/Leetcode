class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(len<My.size()){
            for(int i=0;i<My.size();++i){
                if(i<len){
                    My.push(My.front());
                    My.pop();
                }
                else My.pop();
            }
            My.push(x);
            len++;
        }
        else{
            My.push(x);
            len++;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        len--;
        int res=My.back();
        for(int i=0;i<My.size();++i){
            if(i<len){
                My.push(My.front());
                My.pop();
            }
            else My.pop();
        }
        return res;
    }
    
    /** Get the top element. */
    int top() {
        return My.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return My.empty();
    }
private:
    queue<int>My;
    int len=0;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
