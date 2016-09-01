class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      sort(nums1.begin(), nums1.end());
      sort(nums2.begin(), nums2.end());
      vector<int> result;
      auto i = nums1.begin(), j = nums2.begin();
      while (i != nums1.end() && j!= nums2.end()) {
        if (*i > *j)
          j++;
        else if (*i < *j)
          i++;
        else {
          result.push_back(*i++);
          j++;
        }
      }
      return result;
    }
};
