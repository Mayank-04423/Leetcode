class MinStack {
    //custom stack to maintain the min value till that point
    stack<pair<int,int>>custom;
public:
    MinStack() {}
    
    void push(int value) {
        if(custom.empty()){
            custom.push({value,value});
        }else{
            int currMin = min(value,custom.top().second);
            custom.push({value,currMin});
        }
    }
    
    void pop() {
        custom.pop();
    }
    
    int top() {
        return custom.top().first;
    }
    
    int getMin() {
        return custom.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */