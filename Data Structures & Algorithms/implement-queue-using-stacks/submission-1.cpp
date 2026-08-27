class MyQueue {
private:
    stack<int> myQueue;
    stack<int> topStack;
public:
    MyQueue() {
    }
    
    void push(int x) {
        topStack.push(x);
        int size = myQueue.size();
        for (int i = 0; i < size; i++) {
            topStack.push(myQueue.top());
            myQueue.pop();
        }
        myQueue.push(x);
        for (int i = 0; i < size; i++) {
            myQueue.push(topStack.top());
            topStack.pop();
        }
    }
    
    int pop() {
        int top = myQueue.top();
        int size = myQueue.size();
        for (int i = 0; i < size-1; i++) {
            myQueue.push(topStack.top());
            topStack.pop();
        }
        topStack.pop();
        for (int i = 0; i < size-1; i++) {
            topStack.push(myQueue.top());
            myQueue.pop();
        }
        myQueue.pop();
        return top;
    }
    
    int peek() {
        return myQueue.top();
    }
    
    bool empty() {
        return myQueue.empty();
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