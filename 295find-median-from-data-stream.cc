class MedianFinder {
public:
  priority_queue<int> sm;
  priority_queue<int, vector<int>, greater<int>> lg;
  int median;
  bool isempty = true;
  // Adds a number into the data structure.
  void addNum(int num) {
    if (isempty) {
      isempty= false;
      median = num;
    }
    else {
      if (num < median)
        sm.push(num);
      else
        lg.push(num);
      rebalance();
    }
  }
  // Returns the median of current data stream
  double findMedian() {
    return sm.size() == lg.size() ? median : 0.5*median+0.5*lg.top();
  }
private:
  void rebalance() {
    if (sm.size() > lg.size()) {
      lg.push(median);
      median = sm.top();
      sm.pop();
    }
    else if (lg.size() > sm.size()+1) {
      sm.push(median);
      median = lg.top();
      lg.pop();
    }
  }
};

// MaskRay's Solution
class MedianFinder {
public:
  priority_queue<int> mx;
  priority_queue<int, vector<int>, greater<int>> mi;
  // Adds a number into the data structure.
  void addNum(int num) {
    mx.push(num);
    mi.push(mx.top());
    mx.pop();
    if (mx.size() < mi.size()) {
      mx.push(mi.top());
      mi.pop();
    }
  }

  // Returns the median of current data stream
  double findMedian() {
    return mx.size() > mi.size() ? mx.top() : 0.5 * mx.top() + 0.5 * mi.top();
  }
};
