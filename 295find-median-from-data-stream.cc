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
