class Solution {
public:
  int hIndex(vector<int>& c) {
    int l = c.size(), k = 1;
    for (int i = l-1; k <= l; i--, k++)
      if (c[i] < k) break;
    return --k;
  }
};

//O(log n) solution
class Solution {
public:
  int hIndex(vector<int>& c) {
    int len = c.size(), l = 0, h = len-1;
    while (l<=h) {
      int m = l+(h-l)/2;
      if (c[m]>len-m)
        h = m-1;
      else if (c[m]<len-m)
        l = m+1;
      else
        return len-m;
    }
    return len-l;
  }
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size(), first = 0, mid, count = size, step;
        while (count > 0) {
            step = count / 2;
            mid = first + step;
            if (citations[mid] < size - mid) {
                first = mid + 1;
                count -= (step + 1);
            }
            else
                count = step;
        }
        return size - first;
    }
};
