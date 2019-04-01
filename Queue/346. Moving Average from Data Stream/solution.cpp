class MovingAverage {
public:
    /** Initialize your data structure here. */
    vector<int>num;
    int maxsize;
    MovingAverage(int size) {
        maxsize=size;
    }
    
    double next(int val) {
        if(num.size()<maxsize){
            num.push_back(val);
            return accumulate(num.begin(),num.end(),0.0)/num.size();
        }
        else{
            num.erase(num.begin());
            num.push_back(val);
            return accumulate(num.begin(),num.end(),0.0)/num.size();
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
