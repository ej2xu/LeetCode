class Solution {
public:
  int findMin(vector<int>& a) {
    int l = 0, h = a.size()-1;
    while (l < h) {
      int m = l+h >> 1;
      if (a[m] > a[h])
        l = m+1;
      else if (a[m] < a[h])
        h = m;
      else h--;
    }
    return a[l];
  }
};

class Solution {
public:
  int findMin(vector<int>& a) {
    int l = 0, h = a.size()-1;
    while (l < h) {
      int m = l+h >> 1;
      if (a[m] > a[h])
        l = m+1;
      else if (a[m] < a[h])
        h = m;
      else if (a[h-1] > a[h])
        break;
      else h--;
    }
    return a[h];
  }
};
