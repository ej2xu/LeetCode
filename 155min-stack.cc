class MinStack {
public:
  MinStack() {}

  void push(int x) {
    all.push(x);
    if (mi.empty() || mi.top() >= x)
      mi.push(x);
  }

  void pop() {
    if (all.top() == mi.top())
      mi.pop();
    all.pop();
  }

  int top() {
    return all.top();
  }

  int getMin() {
    return mi.top();
  }
private:
  stack<int> all, mi;
};

class MinStack {
public:
  MinStack() {}

  void push(int x) {
    if (all.empty())
      min = x;
    all.push(x-min);
    if (x < min)
      min = x;
  }

  void pop() {
    long t = all.top();
    if (t < 0)
      min -= t;
    all.pop();
  }

  int top() {
    long t = all.top();
    if (t < 0) return min;
    return all.top()+min;
  }

  int getMin() {
    return min;
  }
private:
  stack<long> all;
  long min;
};

//MaskRay's Solution
class MinStack {
public:
  MinStack() : s(0), d(INT_MAX) {}
  void push(int x) {
    a.push(x-d);
    if (s++ % 32 == 0)
      b.push(0);
    if (int(x) < int(d)) {
      d = x;
      b.top() |= 1u << (s-1)%32;
    } else
      b.top() &= ~ (1u << (s-1)%32);
  }
  void pop() {
    if (b.top() & 1u << (s-1)%32)
      d -= a.top();
    a.pop();
    if (--s % 32 == 0)
      b.pop();
  }
  int top() {
    return b.top() & (1u << (s-1)%32) ? d : d+a.top();
  }
  int getMin() {
    return d;
  }
private:
  stack<unsigned> a, b;
  unsigned s, d;
};
