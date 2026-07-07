class MinStack {
    stack<int>main_stack;
    stack<int>min_stack;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        main_stack.push(value);

        if(min_stack.empty()){
            min_stack.push(value);
        }else{
            int current_min = min_stack.top();
            if(value < current_min){
                min_stack.push(value);
            }else{
            min_stack.push(current_min);
            };
        }

    }
    
    void pop() {
        main_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return main_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
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