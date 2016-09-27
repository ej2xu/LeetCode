class Solution {
public:
  int trap(vector<int>& height) {
    if (height.size() < 3) return 0;
    int res = 0, i = 0, j = height.size()-1, hl = height[i], hr = height[j];
    while (i < j-1)
      if (hl < hr) {
        res += max(0, hl - height[++i]);
        hl = max(hl, height[i]);
      } else {
        res += max(0, hr - height[--j]);
        hr = max(hr, height[j]);
      }
    return res;
  }
};

//concise version by Stefan
int trap(vector<int>& height) {
    int l = 0, r = height.size()-1, level = 0, water = 0;
    while (l < r) {
        int lower = height[height[l] < height[r] ? l++ : r--];
        level = max(level, lower);
        water += level - lower;
    }
    return water;
}
