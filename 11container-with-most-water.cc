class Solution {
public:
  int maxArea(vector<int>& height) {
    if (height.size() < 2) return 0;
    int i = 0, j = height.size()-1, hl = height[i], hr = height[j], area = min(hl, hr) * (j-i);
    while (i < j) {
      if (hl < hr) {
        while (hl >= height[++i]) ;
        hl = height[i];
      } else {
        while (hr >= height[--j]) ;
        hr = height[j];
      }
      area = max(area, min(hl, hr) * (j-i));
    }
    return area;
  }
};

//Stefan's concise version
int maxArea(vector<int>& height) {
    int water = 0;
    int i = 0, j = height.size() - 1;
    while (i < j) {
        int h = min(height[i], height[j]);
        water = max(water, (j - i) * h);
        while (height[i] <= h && i < j) i++;
        while (height[j] <= h && i < j) j--;
    }
    return water;
}
