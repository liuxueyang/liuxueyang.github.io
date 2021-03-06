class MyQueue {
public:
  stack<int> s1, s2;
  /** Initialize your data structure here. */
  MyQueue() {

  }

  /** Push element x to the back of queue. */
  void push(int x) {
    s1.push(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    if (!s2.empty()) {
      int res = s2.top();
      s2.pop();
      return res;
    }

    while (!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }
    if (s2.empty()) return -1;

    int res = s2.top();
    s2.pop();
    return res;
  }

  /** Get the front element. */
  int peek() {
    if (!s2.empty()) {
      return s2.top();
    }
    while (!s1.empty()) {
      int x = s1.top();
      s1.pop();
      s2.push(x);
    }
    if (s2.empty()) return -1;
    return s2.top();
  }

  /** Returns whether the queue is empty. */
  bool empty() {
    return s1.empty() && s2.empty();
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
