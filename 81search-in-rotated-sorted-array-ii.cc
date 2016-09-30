class Solution {
public:
  bool search(vector<int>& a, int target) {
    int last = a.size()-1, l = 0, h = last, m = 0;
    while (l < h) {
      m = l+h+1 >> 1;
      if (a[m] < a[l])
        h = m-1;
      else if (a[m] > a[l])
        l = m;
      else if (a[l] > a[l+1])
          h = l;
      else l++;
    }
    if (target >= a[0])
      l = 0;
    else {
      l = h+1;
      h = last;
    }
    while (l <= h) {
      m = l+h >> 1;
      if (target < a[m])
        h = m-1;
      else if (target > a[m])
        l = m+1;
      else
        return true;
    }
    return false;
  }
};

//one while loop
class Solution {
public:
  int search(vector<int> &a, int target) {
    int n = a.size(), l = 0, h = n-1;
    while (l <= h) {
      int m = l+h >> 1;
      if (a[m] == target) return true;
      if (a[m] > a[h]) {
        if (a[m] > target && a[l] <= target) h = m-1;
        else l = m+1;
      } else if (a[m] < a[h]) {
        if (a[m] < target && a[h] >= target) l = m+1;
        else h = m-1;
      } else
        h--;
    }
    return false;
  }
};

//yet another one from MaskRay
class Solution {
public:
  bool search(vector<int> &a, int target) {
    int l = 0, h = a.size();
    while (l < h) {
      while (l+1 < h && a[l] == a[l+1])
        l++;
      int m = l+h >> 1;
      if (a[m] < target) {
        if (target < a[l] || a[l] < a[m])
          l = m+1;
        else
          h = m;
      } else if (a[m] > target) {
        if (a[l] <= target || a[l] >= a[m])
          h = m;
        else
          l = m+1;
      } else
        return true;
    }
    return false;
  }
};
