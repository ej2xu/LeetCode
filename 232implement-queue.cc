class Queue {
public:
  // Push element x to the back of queue.
  void push(int x) {
    b.push(x);
  }

  // Removes the element from in front of queue.
  void pop(void) {
    reverse();
    a.pop();
  }

  // Get the front element.
  int peek(void) {
    reverse();
    return a.top();
  }

  // Return whether the queue is empty.
  bool empty(void) {
    return a.empty() && b.empty();
  }
private:
  stack<int> a, b;
  void reverse() {
    if (a.empty()) {
      while (!b.empty()) {
        a.push(b.top());
        b.pop();
      }
    }
  }
};
