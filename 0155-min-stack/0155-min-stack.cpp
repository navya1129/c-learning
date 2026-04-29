class MinStack {
public:
    stack<int> s;
    int mini = INT_MAX;
    map<int,int> m;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        m[val]++;
    }
    
    void pop() {
        int top = s.top();
        m[top]--;
        if(m[top] == 0) m.erase(top);
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        for(auto i:m) return i.first;
        return 0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */