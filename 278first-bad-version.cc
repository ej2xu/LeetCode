// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
      int l = 1;
      while (l < n) {
        int mid = l+ (n-l)/2;
        if (isBadVersion(mid))
          n = mid;
        else l = mid+1;
      }
      return l;
    }
};
