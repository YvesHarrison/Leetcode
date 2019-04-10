class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int>s;
    MyQueue() {
        stack<int>s;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int>tmp;
        stack<int>tra;
        tmp.push(x);
        while(!s.empty()){
            tra.push(s.top());
            s.pop();
        }
        while(!tra.empty()){
            tmp.push(tra.top());
            tra.pop();
        }
        s = tmp;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int k = s.top();
        s.pop();
        return k;
    }
    
    /** Get the front element. */
    int peek() {
       return s.top(); 
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
