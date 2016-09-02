class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int size = digits.size(), cur = size-1;
      while (cur >= 0 && digits[cur] == 9)
        digits[cur--] = 0;
      if (cur < 0) {
        digits.assign(size+1, 0);
        digits[0] = 1;
      }
      else digits[cur]++;
      return digits;
    }
};

//MaskRay's solution using find_if
class Solution {
public:
  vector<int> plusOne(vector<int> &a) {
    using namespace std::placeholders;
    if (find_if(a.begin(), a.end(), bind(not_equal_to<int>(), _1, 9)) == a.end()) {
      a.assign(a.size()+1, 0);
      a[0] = 1;
    } else {
      int i = a.size();
      while (++a[--i] >= 10)
        a[i] -= 10;
    }
    return a;
  }
};
