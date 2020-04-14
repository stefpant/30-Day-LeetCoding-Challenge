class MinStack {
    vector<int> stack;
    int minElem;
public:
    /** initialize your data structure here. */
    MinStack() :stack{}{ }
    
    void push(int x) {
        stack.push_back(x);
        if(stack.size() == 1)
            minElem = x;
        else if(x<minElem)
            minElem = x;
    }
    
    void pop() {
        int toRemove = stack.back();
        stack.pop_back();
        if(toRemove == minElem)
            minElem = *min_element(stack.begin(), stack.end());
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minElem;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
